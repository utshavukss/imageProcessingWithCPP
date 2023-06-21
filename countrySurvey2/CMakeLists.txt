cmake_minimum_required(VERSION 3.13.4)

project(countrySurvey)

add_executable(countrySurvey_exe country-survey.cpp)
add_library(my_library functionDefs.cpp)

target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(countrySurvey_exe my_library)

install(TARGETS countrySurvey_exe DESTINATION bin)
install(TARGETS my_library DESTINATION lib)
install(FILES headerfile.h DESTINATION include)