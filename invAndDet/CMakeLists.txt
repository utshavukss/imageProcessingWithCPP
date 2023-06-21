cmake_minimum_required(VERSION 3.13.4)

project(detInv)

add_executable(detInv main.cpp)
add_library(libb matrixClass.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_include_directories(libb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(detInv libb ${OpenCV_LIBS})