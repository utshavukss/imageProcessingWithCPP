cmake_minimum_required(VERSION 3.14.4)

project(res)

add_executable(res main.cpp)
add_library(libb matrixClass.cpp)
target_include_directories(res PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(res libb ${OpenCV_LIBS})