#include "Processes.h"
#include "ProcessesImpl.h"
#include "ProcessesFactory.h"

ProcessList::ProcessList() : m_impl(nullptr) {
    m_impl = ProcessesFactory::Get().MakeProcesses();
}

ProcessList::~ProcessList() {
    delete m_impl;
    m_impl = nullptr;
}

void ProcessList::Scan() {
    if (m_impl) {
        m_impl->Scan();
    }
}

const char* ProcessList::GetName(int i) const {
    return m_impl ? m_impl->GetName(i) : "";
}

int ProcessList::GetPID(int i) const {
    return m_impl ? m_impl->GetPID(i) : -1;
}

int ProcessList::GetCount() const {
    return m_impl ? m_impl->GetCount() : 0;
}