#include "../../include/AppManager.h"
#include "../../include/FileManager.h"

AppManager* AppManager::s_instance = nullptr;

AppManager::AppManager() {
    m_initialized = 0;
}

AppManager::~AppManager() {
    Shutdown();
}

AppManager* AppManager::GetInstance() {
    if (!s_instance) {
        s_instance = new AppManager();
    }
    return s_instance;
}

int AppManager::Init() {
    if (m_initialized) {
        return 0;
    }

    FileManager* fileMgr = FileManager::GetInstance();
    if (!fileMgr) {
        return -1;
    }

    m_initialized = 1;
    return 0;
}

int AppManager::Shutdown() {
    if (!m_initialized) {
        return 0;
    }

    m_initialized = 0;
    return 0;
}