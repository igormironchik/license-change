
project(LicenseChange)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Gui REQUIRED)

set(SRC main.cpp
    mainwindow.h
    mainwindow.cpp
    delayedexecutiontimer.cpp
    opts_dialog.cpp
    proxy.cpp
    textedit.cpp
    worker.cpp
    delayedexecutiontimer.h
    opts_dialog.h
    proxy.h
    textedit.h
    worker.h
    opts_dialog.ui
    info_dialog.h
    info_dialog.cpp
    info_dialog.ui)

qt6_add_resources(SRC resources.qrc)

if(WIN32)
    list(APPEND SRC app.rc)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../utils)

add_executable(LicenseChange ${SRC})

target_link_libraries(LicenseChange utils Qt6::Widgets Qt6::Gui Qt6::Core)
