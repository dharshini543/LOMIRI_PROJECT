cmake_minimum_required(VERSION 3.17)
project(ProcessControl-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

add_definitions(-DSM_BUSNAME=sessionBus)

find_package(Qt6DBus REQUIRED)
find_package(Qt6Qml REQUIRED)

qt_add_qml_module(ProcessControl-qml
    URI ProcessControl
    VERSION 0.1
    SOURCES
    LocationWatcher.h
    LocationWatcher.cpp
    ProcessControl.h
    ProcessControl.cpp
    plugin.h
    plugin.cpp
)

target_link_libraries(ProcessControl-qml
    PRIVATE
    Qt6::DBus Qt6::Qml
)

target_include_directories(ProcessControl-qml PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set(DBUS_IFACE_DIR "${CMAKE_INSTALL_PREFIX}/share/dbus-1/interfaces")

install(FILES com.lomiri.ProcessControl.xml
    DESTINATION "${DBUS_IFACE_DIR}"
)
