#pragma once

class ProcessesImpl;

class ProcessList {
public:
    ProcessList();
    ~ProcessList();

    void Scan();
    int GetCount() const;
    const char* GetName(int i) const;
    int GetPID(int i) const;

private:
    ProcessesImpl* m_impl;
};