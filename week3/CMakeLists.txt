cmake_minimum_required(VERSION 3.13.4)

project(dsa3)

add_executable(dsa3 main.cpp)
add_library(sol solutions.cpp)

target_include_directories(sol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dsa3 sol)