cmake_minimum_required(VERSION 3.20)
project(CrossPlatform)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base aui)
include(${wxWidgets_USE_FILE})

set(COMMON_SOURCES
        src/main.cpp
        src/common/Processes.cpp
        src/ui/MyApp.cpp
        src/ui/MyFrame.cpp
)

if(WIN32)
    set(PLATFORM_SOURCES
            src/platforms/windows/WindowsFactory.cpp
            src/platforms/windows/WindowsProcessesImpl.cpp
            src/platforms/windows/WindowsFilesImpl.cpp)
elseif(APPLE)
    set(PLATFORM_SOURCES
            src/platforms/cocoa/CocoaFactory.cpp
            src/platforms/cocoa/CocoaProcessesImpl.cpp)
else() # Linux 등
    set(PLATFORM_SOURCES
            src/platforms/linux/LinuxFactory.cpp
            src/platforms/linux/LinuxProcessesImpl.cpp)
endif()

add_executable(${PROJECT_NAME} ${COMMON_SOURCES} ${PLATFORM_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE psapi)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
        include
        src/common
        src/ui
)
