cmake_minimum_required(VERSION 3.20)
project(CrossPlatform)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base aui)
include(${wxWidgets_USE_FILE})

set(COMMON_SOURCES
        src/main.cpp
        src/common/AppManager.cpp
        src/common/Processes.cpp
        src/common/FileManager.cpp
        src/ui/MainFrame.cpp
        src/ui/wxApp.cpp
)

if(WIN32)
    set(PLATFORM_SOURCES
            src/platforms/windows/WindowsFactory.cpp
            src/platforms/windows/WindowsProcessesImpl.cpp)
    set(GUI_TYPE WIN32)
elseif(APPLE)
    set(PLATFORM_SOURCES
            src/platforms/cocoa/CocoaFactory.cpp
            src/platforms/cocoa/CocoaProcessesImpl.cpp)
    set(GUI_TYPE MACOSX_BUNDLE)
else()
    set(PLATFORM_SOURCES
            src/platforms/linux/LinuxFactory.cpp
            src/platforms/linux/LinuxProcessesImpl.cpp)
    set(GUI_TYPE "")
endif()

add_executable(${PROJECT_NAME} ${GUI_TYPE} ${COMMON_SOURCES} ${PLATFORM_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE psapi)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
        include
        src/common
        src/ui
)
