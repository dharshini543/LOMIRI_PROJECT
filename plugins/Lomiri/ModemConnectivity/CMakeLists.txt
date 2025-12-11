cmake_minimum_required(VERSION 3.17)
project(ModemConnectivity LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6Qml REQUIRED)
find_package(Qt6DBus REQUIRED)
find_package(Qt6Core REQUIRED)

qt_add_qml_module(ModemConnectivity
    URI Lomiri.ModemConnectivity
    VERSION 0.1
    SOURCES
    plugin.h
    plugin.cpp
    ModemConnectivity.h
    ModemConnectivity.cpp)

target_link_libraries(ModemConnectivity PRIVATE Qt6::Qml Qt6::DBus Qt6::Core)

