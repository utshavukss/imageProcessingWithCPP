cmake_minimum_required(VERSION 3.13.4)

project(dsa2)

add_executable(dsa2 main.cpp)
add_library(sol solutions.cpp)

target_include_directories(dsa2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dsa2 sol)
