#pragma once
#include "FilesImpl.h"

class WindowsFilesImpl : public FilesImpl {
public:
    int GetFileList(const char* path, FileInfo* buffer, int bufferSize) override;
};