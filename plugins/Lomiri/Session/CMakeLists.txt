cmake_minimum_required(VERSION 3.17)
project(LomiriSession-qml LANGUAGES CXX)

add_compile_definitions(QT_NO_KEYWORDS)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../src/liblomiri-private liblomiri-private)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GIO REQUIRED gio-2.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)
find_package(Qt6DBus REQUIRED)
find_package(Qt6Qml REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${GIO_INCLUDE_DIRS}
    ${GLIB_INCLUDE_DIRS}
    ${liblomiri-private_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../../../src/liblomiri-private
)

add_definitions(-DSM_BUSNAME=systemBus)

qt_add_qml_module(LomiriSession-qml
    URI Lomiri.Session
    VERSION 0.1
    SOURCES
    plugin.h
    plugin.cpp
    dbuslomirisessionservice.h
    dbuslomirisessionservice.cpp
    orientationlock.h
    orientationlock.cpp)

target_link_libraries(LomiriSession-qml
    PRIVATE
    Qt6::DBus Qt6::Qml
    lomiri-private
    ${GIO_LDFLAGS}
    ${GLIB_LIBRARIES}
)



