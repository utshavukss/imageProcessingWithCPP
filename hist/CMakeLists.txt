cmake_minimum_required(VERSION 3.13.4)

project(historam)

add_executable(hist main.cpp)
add_library(li matrixClass.cpp)

find_package(OpenCV REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Development NumPy)

# Set the path to the matplotlibcpp.h header file
set(MATPLOTLIBCPP_INCLUDE_DIR /home/utshavuks/Documents/internship/matplotlib/matplotlib-cpp-master)

# Add the matplotlibcpp library as an INTERFACE library
add_library(matplotlibcpp INTERFACE)

# Set the include directory for the matplotlibcpp library target
target_include_directories(matplotlibcpp INTERFACE ${MATPLOTLIBCPP_INCLUDE_DIR} ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})


include_directories(${OpenCV_INCLUDE_DIRS})

target_include_directories(hist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(hist li ${OpenCV_LIBS} matplotlibcpp Python3::Python Python3::NumPy)