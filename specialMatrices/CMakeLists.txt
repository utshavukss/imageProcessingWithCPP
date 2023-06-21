cmake_minimum_required(VERSION 3.13.4)

project(spMatrix)

add_executable(${PROJECT_NAME} main.cpp)
add_library(libb matrixClass.cpp)

target_include_directories(libb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} libb ${OpenCV_LIBS})