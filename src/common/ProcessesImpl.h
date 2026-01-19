#ifndef CROSSPLATFORM_PROCESSESIMPL_H
#define CROSSPLATFORM_PROCESSESIMPL_H

#define MAX_PROCESS_NAME 256

struct ProcessInfo {
    int pid;
    char name[MAX_PROCESS_NAME];
};

class ProcessesImpl {
public:
    virtual ~ProcessesImpl() {}
    virtual int Scan() = 0;
    virtual int GetCount() = 0;
    virtual const char* GetName(int index) = 0;
    virtual int GetPID(int index) = 0;

protected:
    ProcessInfo* m_list;
    int m_count;
    int m_capacity;
};

#endif //CROSSPLATFORM_PROCESSESIMPL_H