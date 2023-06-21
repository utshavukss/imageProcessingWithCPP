cmake_minimum_required(VERSION 3.13.4)

project(basicMatOperaitons)

add_executable(main_exe main.cpp)
add_library(libb matrixClass.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_include_directories(main_exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main_exe libb ${OpenCV_LIBS})