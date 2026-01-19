#pragma once
#include "ProcessesImpl.h"

class WindowsProcessesImpl : public ProcessesImpl {
public:
    WindowsProcessesImpl();
    ~WindowsProcessesImpl() override;

    int Scan() override;
    int GetCount() override;
    const char* GetName(int index) override;
    int GetPID(int index) override;
};