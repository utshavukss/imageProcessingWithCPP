cmake_minimum_required(VERSION 3.13.4)

project(subMatrices)

add_executable(subm main.cpp)
add_library(matrix matrixClass.cpp)

target_include_directories(subm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(subm matrix ${OpenCV_LIBS})