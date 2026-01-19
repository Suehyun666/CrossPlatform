#include "../../include/ProcessesFactory.h"
#include "WindowsProcessesImpl.h"
#include "WindowsFilesImpl.h"

class WindowsFactory : public ProcessesFactory {
public:
    ProcessesImpl* MakeProcesses() override {
        return new WindowsProcessesImpl();
    }

    FilesImpl* MakeFiles() override {
        return new WindowsFilesImpl();
    }

    GUIImpl* MakeGUI() override {
        return nullptr;
    }
};

ProcessesFactory* ProcessesFactory::GetPlatformFactory() {
    static WindowsFactory factory;
    return &factory;
}
