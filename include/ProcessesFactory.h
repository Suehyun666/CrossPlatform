#pragma once

class ProcessesImpl;
class GUIImpl;
class FilesImpl;

class ProcessesFactory {
public:
    virtual ~ProcessesFactory() = default;

    virtual ProcessesImpl* MakeProcesses() = 0;
    virtual FilesImpl* MakeFiles() = 0;
    virtual GUIImpl* MakeGUI() = 0;

    static ProcessesFactory& Get() {
        return *GetPlatformFactory(); 
    }

private:
    static ProcessesFactory* GetPlatformFactory();
};