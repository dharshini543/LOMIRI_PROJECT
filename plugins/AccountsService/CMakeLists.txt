cmake_minimum_required(VERSION 3.17)
set(CMAKE_AUTOMOC ON)

project(AccountsServiceQml LANGUAGES CXX)

add_definitions(-DSM_BUSNAME=systemBus)
include_directories(${GLIB_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../../include/paths.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/paths.h)

find_package(Qt6 REQUIRED COMPONENTS Qml DBus)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0 gio-2.0 gobject-2.0)

qt_add_qml_module(AccountsService-qml
    URI AccountsService
    VERSION 0.1
    SOURCES
    AccountsService.h
    AccountsService.cpp
    AccountsServiceDBusAdaptor.h
    AccountsServiceDBusAdaptor.cpp
    plugin.h
    plugin.cpp
)

target_link_libraries(AccountsService-qml
    PRIVATE
    Qt6::DBus Qt6::Qml
    ${GLIB_LIBRARIES}
)

set(DBUS_IFACE_DIR "${CMAKE_INSTALL_PREFIX}/share/dbus-1/interfaces")
set(ACCOUNTS_IFACE_DIR "${CMAKE_INSTALL_PREFIX}/share/accountsservice/interfaces")

install(FILES com.lomiri.shell.AccountsService.xml
    DESTINATION "${DBUS_IFACE_DIR}"
)

# Create accountsservice symlink for above dbus interface
install(CODE "
    execute_process(COMMAND mkdir -p \"\$ENV{DESTDIR}${ACCOUNTS_IFACE_DIR}\")
    execute_process(COMMAND ln -sf ../../dbus-1/interfaces/com.lomiri.shell.AccountsService.xml \"\$ENV{DESTDIR}${ACCOUNTS_IFACE_DIR}\")
    ")
