cmake_minimum_required(VERSION 3.5)

project(Sudoku_Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(OpenCV_DIR /Users/henrydyer/Documents/OpenCV/installation/OpenCV/lib/cmake/opencv4)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package( OpenCV REQUIRED )
find_package( PkgConfig REQUIRED )

pkg_search_module ( TESSERACT REQUIRED tesseract )
pkg_search_module ( LEPTONICA REQUIRED lept )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        gameoptiondialog.h
        gameoptiondialog.cpp
        gameoptiondialog.ui
        photoboarddialog.h
        photoboarddialog.cpp
        photoboarddialog.ui
        computerboarddialog.h
        computerboarddialog.cpp
        computerboarddialog.ui
        Square.cpp
        Board.cpp
        CVBoard.cpp
        GenBoard.cpp
        Board.h
        Square.h
        CVBoard.h
        GenBoard.h
        resources.qrc
)

include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories( ${TESSERACT_INCLUDE_DIRS} )
include_directories( ${LEPTONICA_INCLUDE_DIRS})

link_directories( ${TESSERACT_LIBRARY_DIRS} )
link_directories( ${LEPTONICA_LIBRARY_DIRS} )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Sudoku_Project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Sudoku_Project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Sudoku_Project SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Sudoku_Project
            main.cpp Board.cpp CVBoard.cpp Square.cpp GenBoard.cpp resources.qrc
        )
    endif()
endif()

target_link_libraries(Sudoku_Project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Sudoku_Project PRIVATE ${OpenCV_LIBS})
target_link_libraries(Sudoku_Project PRIVATE ${TESSERACT_LIBRARIES})
target_link_libraries(Sudoku_Project PRIVATE ${LEPTONICA_LIBRARIES})

set_target_properties(Sudoku_Project PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Sudoku_Project)
endif()






#add_example(sampleCode2) and so on
