cmake_minimum_required(VERSION 3.17)
project(ApplicationMenu-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6DBus REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Qml Quick)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

qt_add_dbus_adaptor(applicationMenu_SRCS
    com.lomiri.MenuRegistrar.xml
    dbusapplicationmenuregistry.h
    DBusApplicationMenuRegistry
)
qt_add_qml_module(ApplicationMenu-qml
    URI Lomiri.ApplicationMenu
    VERSION 0.1
    SOURCES
    applicationmenuregistry.h
    applicationmenuregistry.cpp
    dbusapplicationmenuregistry.h
    dbusapplicationmenuregistry.cpp
    plugin.h
    plugin.cpp
    ${applicationMenu_SRCS}
)

target_link_libraries(ApplicationMenu-qml
    PRIVATE Qt6::DBus Qt6::Qml Qt6::Quick)

