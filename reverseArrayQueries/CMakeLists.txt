cmake_minimum_required(VERSION 3.13.4)

project(Reverse_Array_Queries)

add_executable(array_exe main.cpp)
add_library(declarations_h reverse.cpp)

target_include_directories(declarations_h PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(array_exe declarations_h)