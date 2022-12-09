cmake_minimum_required(VERSION 3.16)

project(inputfilepath VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(inputfilepath
    main.cpp
)

qt_add_resources(inputfilepath rcc PREFIX "/temp/" FILES test.txt)

qt_add_qml_module(inputfilepath
    URI untitled
    VERSION 1.0
    QML_FILES main.qml MyButton.qml
    SOURCES mycomponent.h mycomponent.cpp
)

set_target_properties(inputfilepath PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(inputfilepath
    PRIVATE Qt6::Quick)

install(TARGETS inputfilepath
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
