# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /workspaces/odas/odas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/odas/odas/build

# Include any dependencies generated for this target.
include CMakeFiles/odasserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/odasserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/odasserver.dir/flags.make

CMakeFiles/odasserver.dir/demo/odasserver/main.o: CMakeFiles/odasserver.dir/flags.make
CMakeFiles/odasserver.dir/demo/odasserver/main.o: ../demo/odasserver/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/odas/odas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/odasserver.dir/demo/odasserver/main.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/odasserver.dir/demo/odasserver/main.o   -c /workspaces/odas/odas/demo/odasserver/main.c

CMakeFiles/odasserver.dir/demo/odasserver/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/odasserver.dir/demo/odasserver/main.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/odas/odas/demo/odasserver/main.c > CMakeFiles/odasserver.dir/demo/odasserver/main.i

CMakeFiles/odasserver.dir/demo/odasserver/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/odasserver.dir/demo/odasserver/main.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/odas/odas/demo/odasserver/main.c -o CMakeFiles/odasserver.dir/demo/odasserver/main.s

# Object files for target odasserver
odasserver_OBJECTS = \
"CMakeFiles/odasserver.dir/demo/odasserver/main.o"

# External object files for target odasserver
odasserver_EXTERNAL_OBJECTS =

../bin/odasserver: CMakeFiles/odasserver.dir/demo/odasserver/main.o
../bin/odasserver: CMakeFiles/odasserver.dir/build.make
../bin/odasserver: ../lib/libodas.so
../bin/odasserver: CMakeFiles/odasserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/odas/odas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/odasserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/odasserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/odasserver.dir/build: ../bin/odasserver

.PHONY : CMakeFiles/odasserver.dir/build

CMakeFiles/odasserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/odasserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/odasserver.dir/clean

CMakeFiles/odasserver.dir/depend:
	cd /workspaces/odas/odas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/odas/odas /workspaces/odas/odas /workspaces/odas/odas/build /workspaces/odas/odas/build /workspaces/odas/odas/build/CMakeFiles/odasserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/odasserver.dir/depend

