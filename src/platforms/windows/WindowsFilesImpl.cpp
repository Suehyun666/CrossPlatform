#include "WindowsFilesImpl.h"
#include <windows.h>
#include <string.h>

int WindowsFilesImpl::GetFileList(const char* path, FileInfo* buffer, int bufferSize) {
    if (!path || !buffer || bufferSize <= 0) {
        return -1;
    }

    char searchPath[MAX_PATH];
    strncpy(searchPath, path, MAX_PATH - 3);
    searchPath[MAX_PATH - 3] = '\0';
    strcat(searchPath, "\\*");

    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return 0;
    }

    int count = 0;
    do {
        if (count >= bufferSize) {
            break;
        }

        strncpy(buffer[count].name, findData.cFileName, MAX_FILENAME - 1);
        buffer[count].name[MAX_FILENAME - 1] = '\0';

        buffer[count].isDirectory = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? 1 : 0;

        LARGE_INTEGER fileSize;
        fileSize.LowPart = findData.nFileSizeLow;
        fileSize.HighPart = findData.nFileSizeHigh;
        buffer[count].size = fileSize.QuadPart;

        count++;
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);
    return count;
}