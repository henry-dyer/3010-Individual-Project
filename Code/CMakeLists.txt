cmake_minimum_required(VERSION 2.8.12)

PROJECT(main)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR /Users/henrydyer/Documents/OpenCV/installation/OpenCV/lib/cmake/opencv4)

find_package( OpenCV REQUIRED )

# INCLUDE OPENCV DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS})

# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_executable(main main.cpp Board.cpp CVBoard.cpp Square.cpp GenBoard.cpp)
target_link_libraries(main ${OpenCV_LIBS})
#add_example(sampleCode2) and so on