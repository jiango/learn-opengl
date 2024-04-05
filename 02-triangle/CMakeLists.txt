cmake_minimum_required(VERSION 3.5)

project(02-triangle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(Qt5_DIR C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5)
find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        MyOpenGLWidget.cpp
        MyOpenGLWidget.h
)

add_executable(02-triangle
        ${PROJECT_SOURCES}
        resource.qrc
)


target_include_directories(02-triangle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(02-triangle PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt5::OpenGL)
