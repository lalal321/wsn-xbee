# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/wsn-xbee/lib/aruco303/utils

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/wsn-xbee/lib/aruco303/utils/build

# Include any dependencies generated for this target.
include CMakeFiles/aruco_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aruco_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aruco_test.dir/flags.make

CMakeFiles/aruco_test.dir/aruco_test.o: CMakeFiles/aruco_test.dir/flags.make
CMakeFiles/aruco_test.dir/aruco_test.o: ../aruco_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/wsn-xbee/lib/aruco303/utils/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aruco_test.dir/aruco_test.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aruco_test.dir/aruco_test.o -c /home/pi/wsn-xbee/lib/aruco303/utils/aruco_test.cpp

CMakeFiles/aruco_test.dir/aruco_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aruco_test.dir/aruco_test.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/wsn-xbee/lib/aruco303/utils/aruco_test.cpp > CMakeFiles/aruco_test.dir/aruco_test.i

CMakeFiles/aruco_test.dir/aruco_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aruco_test.dir/aruco_test.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/wsn-xbee/lib/aruco303/utils/aruco_test.cpp -o CMakeFiles/aruco_test.dir/aruco_test.s

CMakeFiles/aruco_test.dir/aruco_test.o.requires:

.PHONY : CMakeFiles/aruco_test.dir/aruco_test.o.requires

CMakeFiles/aruco_test.dir/aruco_test.o.provides: CMakeFiles/aruco_test.dir/aruco_test.o.requires
	$(MAKE) -f CMakeFiles/aruco_test.dir/build.make CMakeFiles/aruco_test.dir/aruco_test.o.provides.build
.PHONY : CMakeFiles/aruco_test.dir/aruco_test.o.provides

CMakeFiles/aruco_test.dir/aruco_test.o.provides.build: CMakeFiles/aruco_test.dir/aruco_test.o


# Object files for target aruco_test
aruco_test_OBJECTS = \
"CMakeFiles/aruco_test.dir/aruco_test.o"

# External object files for target aruco_test
aruco_test_EXTERNAL_OBJECTS =

aruco_test: CMakeFiles/aruco_test.dir/aruco_test.o
aruco_test: CMakeFiles/aruco_test.dir/build.make
aruco_test: CMakeFiles/aruco_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/wsn-xbee/lib/aruco303/utils/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aruco_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aruco_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aruco_test.dir/build: aruco_test

.PHONY : CMakeFiles/aruco_test.dir/build

CMakeFiles/aruco_test.dir/requires: CMakeFiles/aruco_test.dir/aruco_test.o.requires

.PHONY : CMakeFiles/aruco_test.dir/requires

CMakeFiles/aruco_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aruco_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aruco_test.dir/clean

CMakeFiles/aruco_test.dir/depend:
	cd /home/pi/wsn-xbee/lib/aruco303/utils/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/wsn-xbee/lib/aruco303/utils /home/pi/wsn-xbee/lib/aruco303/utils /home/pi/wsn-xbee/lib/aruco303/utils/build /home/pi/wsn-xbee/lib/aruco303/utils/build /home/pi/wsn-xbee/lib/aruco303/utils/build/CMakeFiles/aruco_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aruco_test.dir/depend
