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
CMAKE_SOURCE_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/week3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/utshavuks/Documents/project1/rebase/utshavp/week3/build

# Include any dependencies generated for this target.
include CMakeFiles/sol.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sol.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sol.dir/flags.make

CMakeFiles/sol.dir/solutions.cpp.o: CMakeFiles/sol.dir/flags.make
CMakeFiles/sol.dir/solutions.cpp.o: ../solutions.cpp
CMakeFiles/sol.dir/solutions.cpp.o: CMakeFiles/sol.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/week3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sol.dir/solutions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sol.dir/solutions.cpp.o -MF CMakeFiles/sol.dir/solutions.cpp.o.d -o CMakeFiles/sol.dir/solutions.cpp.o -c /home/utshavuks/Documents/project1/rebase/utshavp/week3/solutions.cpp

CMakeFiles/sol.dir/solutions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sol.dir/solutions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utshavuks/Documents/project1/rebase/utshavp/week3/solutions.cpp > CMakeFiles/sol.dir/solutions.cpp.i

CMakeFiles/sol.dir/solutions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sol.dir/solutions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utshavuks/Documents/project1/rebase/utshavp/week3/solutions.cpp -o CMakeFiles/sol.dir/solutions.cpp.s

# Object files for target sol
sol_OBJECTS = \
"CMakeFiles/sol.dir/solutions.cpp.o"

# External object files for target sol
sol_EXTERNAL_OBJECTS =

libsol.a: CMakeFiles/sol.dir/solutions.cpp.o
libsol.a: CMakeFiles/sol.dir/build.make
libsol.a: CMakeFiles/sol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/utshavuks/Documents/project1/rebase/utshavp/week3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsol.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sol.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sol.dir/build: libsol.a
.PHONY : CMakeFiles/sol.dir/build

CMakeFiles/sol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sol.dir/clean

CMakeFiles/sol.dir/depend:
	cd /home/utshavuks/Documents/project1/rebase/utshavp/week3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/utshavuks/Documents/project1/rebase/utshavp/week3 /home/utshavuks/Documents/project1/rebase/utshavp/week3 /home/utshavuks/Documents/project1/rebase/utshavp/week3/build /home/utshavuks/Documents/project1/rebase/utshavp/week3/build /home/utshavuks/Documents/project1/rebase/utshavp/week3/build/CMakeFiles/sol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sol.dir/depend

