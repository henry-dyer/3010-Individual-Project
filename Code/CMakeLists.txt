cmake_minimum_required(VERSION 2.8.12)

PROJECT(main)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR /Users/henrydyer/Documents/OpenCV/installation/OpenCV/lib/cmake/opencv4)

find_package( OpenCV REQUIRED )
find_package( PkgConfig REQUIRED )

pkg_search_module ( TESSERACT REQUIRED tesseract )
pkg_search_module ( LEPTONICA REQUIRED lept )

message(STATUS "TEST")

message(STATUS ${LEPTONICA_INCLUDE_DIRS} )
message(STATUS ${TESSERACT_INCLUDE_DIRS} )

# INCLUDE OPENCV DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories( ${TESSERACT_INCLUDE_DIRS} )
include_directories( ${LEPTONICA_INCLUDE_DIRS})

link_directories( ${TESSERACT_LIBRARY_DIRS} )
link_directories( ${LEPTONICA_LIBRARY_DIRS} )

# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_executable(main main.cpp Board.cpp CVBoard.cpp Square.cpp GenBoard.cpp)
target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(main ${TESSERACT_LIBRARIES})
target_link_libraries(main ${LEPTONICA_LIBRARIES})
#add_example(sampleCode2) and so on