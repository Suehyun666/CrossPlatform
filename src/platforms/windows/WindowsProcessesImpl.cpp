#include "WindowsProcessesImpl.h"
#include <windows.h>
#include <psapi.h>
#include <string.h>

WindowsProcessesImpl::WindowsProcessesImpl() {
    m_list = nullptr;
    m_count = 0;
    m_capacity = 0;
}

WindowsProcessesImpl::~WindowsProcessesImpl() {
    if (m_list) {
        delete[] m_list;
        m_list = nullptr;
    }
}

int WindowsProcessesImpl::Scan() {
    if (m_list) {
        delete[] m_list;
        m_list = nullptr;
    }
    m_count = 0;

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        return 0;
    }

    cProcesses = cbNeeded / sizeof(DWORD);

    m_capacity = (int)cProcesses;
    m_list = new ProcessInfo[m_capacity];

    for (unsigned int i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            char szProcessName[MAX_PATH] = "<unknown>";
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i]);

            if (hProcess != nullptr) {
                HMODULE hMod;
                DWORD cbNeededMod;
                if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeededMod)) {
                    GetModuleBaseNameA(hProcess, hMod, szProcessName, sizeof(szProcessName));
                }
                CloseHandle(hProcess);
            }

            m_list[m_count].pid = (int)aProcesses[i];
            strncpy(m_list[m_count].name, szProcessName, MAX_PROCESS_NAME - 1);
            m_list[m_count].name[MAX_PROCESS_NAME - 1] = '\0';
            m_count++;
        }
    }
    return m_count;
}

int WindowsProcessesImpl::GetCount() {
    return m_count;
}

const char* WindowsProcessesImpl::GetName(int index) {
    if (index >= 0 && index < m_count) {
        return m_list[index].name;
    }
    return "";
}

int WindowsProcessesImpl::GetPID(int index) {
    if (index >= 0 && index < m_count) {
        return m_list[index].pid;
    }
    return -1;
}