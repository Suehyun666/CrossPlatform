#pragma once

#define MAX_FILENAME 260

struct FileInfo {
    char name[MAX_FILENAME];
    long long size;
    int isDirectory;
};

class FilesImpl {
public:
    virtual ~FilesImpl() = default;
    virtual int GetFileList(const char* path, FileInfo* buffer, int bufferSize) = 0;
};