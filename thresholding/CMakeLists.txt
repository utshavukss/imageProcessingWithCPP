cmake_minimum_required(VERSION 3.13.4)

project(thresholding)

add_executable(mn main.cpp)
add_library(li matrixClass.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_include_directories(mn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mn li ${OpenCV_LIBS})