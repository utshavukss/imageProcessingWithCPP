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
CMAKE_SOURCE_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/canEdge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build

# Include any dependencies generated for this target.
include CMakeFiles/cann.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cann.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cann.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cann.dir/flags.make

CMakeFiles/cann.dir/matrixClass.cpp.o: CMakeFiles/cann.dir/flags.make
CMakeFiles/cann.dir/matrixClass.cpp.o: ../matrixClass.cpp
CMakeFiles/cann.dir/matrixClass.cpp.o: CMakeFiles/cann.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cann.dir/matrixClass.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cann.dir/matrixClass.cpp.o -MF CMakeFiles/cann.dir/matrixClass.cpp.o.d -o CMakeFiles/cann.dir/matrixClass.cpp.o -c /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/matrixClass.cpp

CMakeFiles/cann.dir/matrixClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cann.dir/matrixClass.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/matrixClass.cpp > CMakeFiles/cann.dir/matrixClass.cpp.i

CMakeFiles/cann.dir/matrixClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cann.dir/matrixClass.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/matrixClass.cpp -o CMakeFiles/cann.dir/matrixClass.cpp.s

# Object files for target cann
cann_OBJECTS = \
"CMakeFiles/cann.dir/matrixClass.cpp.o"

# External object files for target cann
cann_EXTERNAL_OBJECTS =

libcann.a: CMakeFiles/cann.dir/matrixClass.cpp.o
libcann.a: CMakeFiles/cann.dir/build.make
libcann.a: CMakeFiles/cann.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcann.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cann.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cann.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cann.dir/build: libcann.a
.PHONY : CMakeFiles/cann.dir/build

CMakeFiles/cann.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cann.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cann.dir/clean

CMakeFiles/cann.dir/depend:
	cd /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/utshavuks/Documents/project1/rebase/utshavp/canEdge /home/utshavuks/Documents/project1/rebase/utshavp/canEdge /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build /home/utshavuks/Documents/project1/rebase/utshavp/canEdge/build/CMakeFiles/cann.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cann.dir/depend
