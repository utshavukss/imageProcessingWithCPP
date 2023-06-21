cmake_minimum_required(VERSION 3.13.4)

project(SuspiciousLogs)

add_executable(sus_exe main.cpp)
add_library (loganalysis_h functionDefs.cpp)

target_link_libraries(sus_exe loganalysis_h)
target_include_directories(loganalysis_h PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})