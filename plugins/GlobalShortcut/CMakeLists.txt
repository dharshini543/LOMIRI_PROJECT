cmake_minimum_required(VERSION 3.17)
project(GlobalShortcut-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6Quick REQUIRED)
find_package(Qt6Gui REQUIRED)

qt_add_qml_module(GlobalShortcut-qml
    URI GlobalShortcut
    VERSION 1.0
    SOURCES
    globalshortcut.h
    globalshortcut.cpp
    globalshortcutregistry.h
    globalshortcutregistry.cpp
    plugin.h
    plugin.cpp
)

target_link_libraries(GlobalShortcut-qml PRIVATE Qt6::Quick Qt6::Gui)

