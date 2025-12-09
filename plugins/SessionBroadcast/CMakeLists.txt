cmake_minimum_required(VERSION 3.17)
project(SessionBroadcast-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
add_definitions(-DSM_BUSNAME=systemBus)

find_package(Qt6DBus REQUIRED)
find_package(Qt6Qml REQUIRED)

qt_add_qml_module(SessionBroadcast-qml
    URI SessionBroadcast
    VERSION 0.1
    SOURCES
    SessionBroadcast.h
    SessionBroadcast.cpp
    plugin.h
    plugin.cpp)

target_link_libraries(SessionBroadcast-qml
    PRIVATE
    Qt6::DBus Qt6::Qml
    ${GLIB_LIBRARIES}
)

