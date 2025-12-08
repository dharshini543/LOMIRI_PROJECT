# This is a temporary snapshot of the WIP QInputInfo API as we
# require this in lomiri now but upstream isn't finished yet.
# Eventually this should be dropped in favor of the upstream
# QInputInfo API.

cmake_minimum_required(VERSION 3.17)
project(InputInfo LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Quick REQUIRED)
find_package(Qt6Qml REQUIRED )

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUDEV REQUIRED libudev)
pkg_check_modules(LIBEVDEV REQUIRED libevdev)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${LIBUDEV_INCLUDE_DIRS}
    ${LIBEVDEV_INCLUDE_DIRS}
)

qt_add_qml_module(InputInfo
    URI Lomiri.InputInfo
    CLASS_NAME InputInfoPlugin
    VERSION 0.1
    SOURCES
    plugin.h
    plugin.cpp
    qinputinfo.h
    qinputinfo.cpp
    qdeclarativeinputdevicemodel_p.h
    qdeclarativeinputdevicemodel.cpp
    linux/qinputdeviceinfo_linux_p.h
    linux/qinputdeviceinfo_linux.cpp
)

target_link_libraries(InputInfo
    PRIVATE
    ${LIBUDEV_LDFLAGS}
    ${LIBEVDEV_LDFLAGS}
    Qt6::Core Qt6::Qml Qt6::Quick
)

