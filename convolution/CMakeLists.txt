cmake_minimum_required(VERSION 3.13.4)

project(conv)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(conv main.cpp)
add_library(con matrixClass.cpp)

target_include_directories(con PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(conv con ${OpenCV_LIBS})