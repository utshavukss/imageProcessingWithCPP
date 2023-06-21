cmake_minimum_required(VERSION 3.13.4)

project(vukss)

add_library(my_library function.cpp)

target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE my_library)