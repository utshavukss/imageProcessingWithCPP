# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/utshavuks/Documents/project1/utshavp/hist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/utshavuks/Documents/project1/utshavp/hist/build

# Include any dependencies generated for this target.
include CMakeFiles/hist.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hist.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hist.dir/flags.make

CMakeFiles/hist.dir/main.cpp.o: CMakeFiles/hist.dir/flags.make
CMakeFiles/hist.dir/main.cpp.o: ../main.cpp
CMakeFiles/hist.dir/main.cpp.o: CMakeFiles/hist.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utshavuks/Documents/project1/utshavp/hist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hist.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hist.dir/main.cpp.o -MF CMakeFiles/hist.dir/main.cpp.o.d -o CMakeFiles/hist.dir/main.cpp.o -c /home/utshavuks/Documents/project1/utshavp/hist/main.cpp

CMakeFiles/hist.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hist.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utshavuks/Documents/project1/utshavp/hist/main.cpp > CMakeFiles/hist.dir/main.cpp.i

CMakeFiles/hist.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hist.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utshavuks/Documents/project1/utshavp/hist/main.cpp -o CMakeFiles/hist.dir/main.cpp.s

# Object files for target hist
hist_OBJECTS = \
"CMakeFiles/hist.dir/main.cpp.o"

# External object files for target hist
hist_EXTERNAL_OBJECTS =

hist: CMakeFiles/hist.dir/main.cpp.o
hist: CMakeFiles/hist.dir/build.make
hist: libli.a
hist: /usr/local/lib/libopencv_gapi.so.4.7.0
hist: /usr/local/lib/libopencv_highgui.so.4.7.0
hist: /usr/local/lib/libopencv_ml.so.4.7.0
hist: /usr/local/lib/libopencv_objdetect.so.4.7.0
hist: /usr/local/lib/libopencv_photo.so.4.7.0
hist: /usr/local/lib/libopencv_stitching.so.4.7.0
hist: /usr/local/lib/libopencv_video.so.4.7.0
hist: /usr/local/lib/libopencv_videoio.so.4.7.0
hist: /usr/lib/x86_64-linux-gnu/libpython3.10.so
hist: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
hist: /usr/local/lib/libopencv_dnn.so.4.7.0
hist: /usr/local/lib/libopencv_calib3d.so.4.7.0
hist: /usr/local/lib/libopencv_features2d.so.4.7.0
hist: /usr/local/lib/libopencv_flann.so.4.7.0
hist: /usr/local/lib/libopencv_imgproc.so.4.7.0
hist: /usr/local/lib/libopencv_core.so.4.7.0
hist: CMakeFiles/hist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/utshavuks/Documents/project1/utshavp/hist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hist.dir/build: hist
.PHONY : CMakeFiles/hist.dir/build

CMakeFiles/hist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hist.dir/clean

CMakeFiles/hist.dir/depend:
	cd /home/utshavuks/Documents/project1/utshavp/hist/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/utshavuks/Documents/project1/utshavp/hist /home/utshavuks/Documents/project1/utshavp/hist /home/utshavuks/Documents/project1/utshavp/hist/build /home/utshavuks/Documents/project1/utshavp/hist/build /home/utshavuks/Documents/project1/utshavp/hist/build/CMakeFiles/hist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hist.dir/depend

