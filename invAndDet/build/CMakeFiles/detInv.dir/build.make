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
CMAKE_SOURCE_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build

# Include any dependencies generated for this target.
include CMakeFiles/detInv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/detInv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/detInv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/detInv.dir/flags.make

CMakeFiles/detInv.dir/main.cpp.o: CMakeFiles/detInv.dir/flags.make
CMakeFiles/detInv.dir/main.cpp.o: ../main.cpp
CMakeFiles/detInv.dir/main.cpp.o: CMakeFiles/detInv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/detInv.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/detInv.dir/main.cpp.o -MF CMakeFiles/detInv.dir/main.cpp.o.d -o CMakeFiles/detInv.dir/main.cpp.o -c /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/main.cpp

CMakeFiles/detInv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detInv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/main.cpp > CMakeFiles/detInv.dir/main.cpp.i

CMakeFiles/detInv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detInv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/main.cpp -o CMakeFiles/detInv.dir/main.cpp.s

# Object files for target detInv
detInv_OBJECTS = \
"CMakeFiles/detInv.dir/main.cpp.o"

# External object files for target detInv
detInv_EXTERNAL_OBJECTS =

detInv: CMakeFiles/detInv.dir/main.cpp.o
detInv: CMakeFiles/detInv.dir/build.make
detInv: liblibb.a
detInv: /usr/local/lib/libopencv_gapi.so.4.7.0
detInv: /usr/local/lib/libopencv_highgui.so.4.7.0
detInv: /usr/local/lib/libopencv_ml.so.4.7.0
detInv: /usr/local/lib/libopencv_objdetect.so.4.7.0
detInv: /usr/local/lib/libopencv_photo.so.4.7.0
detInv: /usr/local/lib/libopencv_stitching.so.4.7.0
detInv: /usr/local/lib/libopencv_video.so.4.7.0
detInv: /usr/local/lib/libopencv_videoio.so.4.7.0
detInv: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
detInv: /usr/local/lib/libopencv_dnn.so.4.7.0
detInv: /usr/local/lib/libopencv_calib3d.so.4.7.0
detInv: /usr/local/lib/libopencv_features2d.so.4.7.0
detInv: /usr/local/lib/libopencv_flann.so.4.7.0
detInv: /usr/local/lib/libopencv_imgproc.so.4.7.0
detInv: /usr/local/lib/libopencv_core.so.4.7.0
detInv: CMakeFiles/detInv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable detInv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detInv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/detInv.dir/build: detInv
.PHONY : CMakeFiles/detInv.dir/build

CMakeFiles/detInv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detInv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detInv.dir/clean

CMakeFiles/detInv.dir/depend:
	cd /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build /home/utshavuks/Documents/project1/rebase/utshavp/invAndDet/build/CMakeFiles/detInv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detInv.dir/depend
