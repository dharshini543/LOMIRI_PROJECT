cmake_minimum_required(VERSION 3.17)
project(BatteryMonitor LANGUAGES CXX)

find_package(Qt6DBus REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Qml)
set(CMAKE_AUTOMOC ON)

qt_add_qml_module(BatteryMonitor
    URI BatteryMonitor
    VERSION 1.0
    SOURCES
    plugin.h
    plugin.cpp
    BatteryMonitor.h
    BatteryMonitor.cpp
)

target_link_libraries(BatteryMonitor PRIVATE Qt6::DBus Qt6::Qml)

