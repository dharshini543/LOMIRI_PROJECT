cmake_minimum_required(VERSION 3.17)
project(Platform-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6DBus REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Qml Quick)

qt_add_qml_module(Platform-qml
    URI Lomiri.Platform
    VERSION 1.0
    SOURCES
    platform.h
    platform.cpp
    plugin.h
    plugin.cpp
)

target_link_libraries(Platform-qml
    PRIVATE
    Qt6::DBus
    Qt6::Qml)

