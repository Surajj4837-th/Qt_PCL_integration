cmake_minimum_required(VERSION 3.5)

project(QT_PCL_integrate LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(VTK
    REQUIRED
    COMPONENTS
        GUISupportQt
        IOLegacy)

find_package(PCL REQUIRED)
include_directories( ${PCL_INCLUDE_DIRS} )
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


set(PROJECT_SOURCES
        main.cpp
        pclviewer.cpp
        pclviewer.h
        pclviewer.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QT_PCL_integrate
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(QT_PCL_integrate SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QT_PCL_integrate
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QT_PCL_integrate PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
