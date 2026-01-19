#include "../../include/ProcessesFactory.h"
#include "WindowsProcessesImpl.h"

class WindowsFactory : public ProcessesFactory {
public:
    ProcessesImpl* MakeProcesses() override {
        return new WindowsProcessesImpl();
    }
};

ProcessesFactory* ProcessesFactory::GetPlatformFactory() {
    static WindowsFactory factory;
    return &factory;
}
