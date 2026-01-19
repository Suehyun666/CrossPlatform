#pragma once

class ProcessesImpl;

class ProcessesFactory {
public:
    virtual ~ProcessesFactory() = default;

    virtual ProcessesImpl* MakeProcesses() = 0;

    static ProcessesFactory& Get() {
        return *GetPlatformFactory();
    }

private:
    static ProcessesFactory* GetPlatformFactory();
};