# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/hatf0/dev/blocklandjs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hatf0/dev/blocklandjs/build

# Include any dependencies generated for this target.
include CMakeFiles/duktape.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/duktape.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/duktape.dir/flags.make

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj: CMakeFiles/duktape.dir/flags.make
CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj: CMakeFiles/duktape.dir/includes_C.rsp
CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj: ../lib/duktape/src/duktape.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hatf0/dev/blocklandjs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj"
	/usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj   -c /home/hatf0/dev/blocklandjs/lib/duktape/src/duktape.c

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.i"
	/usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hatf0/dev/blocklandjs/lib/duktape/src/duktape.c > CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.i

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.s"
	/usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hatf0/dev/blocklandjs/lib/duktape/src/duktape.c -o CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.s

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.requires:

.PHONY : CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.requires

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.provides: CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.requires
	$(MAKE) -f CMakeFiles/duktape.dir/build.make CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.provides.build
.PHONY : CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.provides

CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.provides.build: CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj


# Object files for target duktape
duktape_OBJECTS = \
"CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj"

# External object files for target duktape
duktape_EXTERNAL_OBJECTS =

libduktape.a: CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj
libduktape.a: CMakeFiles/duktape.dir/build.make
libduktape.a: CMakeFiles/duktape.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hatf0/dev/blocklandjs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libduktape.a"
	$(CMAKE_COMMAND) -P CMakeFiles/duktape.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/duktape.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/duktape.dir/build: libduktape.a

.PHONY : CMakeFiles/duktape.dir/build

CMakeFiles/duktape.dir/requires: CMakeFiles/duktape.dir/lib/duktape/src/duktape.c.obj.requires

.PHONY : CMakeFiles/duktape.dir/requires

CMakeFiles/duktape.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/duktape.dir/cmake_clean.cmake
.PHONY : CMakeFiles/duktape.dir/clean

CMakeFiles/duktape.dir/depend:
	cd /home/hatf0/dev/blocklandjs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hatf0/dev/blocklandjs /home/hatf0/dev/blocklandjs /home/hatf0/dev/blocklandjs/build /home/hatf0/dev/blocklandjs/build /home/hatf0/dev/blocklandjs/build/CMakeFiles/duktape.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/duktape.dir/depend
