# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CLion\JniDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\JniDemo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JniDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JniDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JniDemo.dir/flags.make

CMakeFiles/JniDemo.dir/main.c.obj: CMakeFiles/JniDemo.dir/flags.make
CMakeFiles/JniDemo.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\JniDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/JniDemo.dir/main.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\JniDemo.dir\main.c.obj   -c E:\CLion\JniDemo\main.c

CMakeFiles/JniDemo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/JniDemo.dir/main.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\JniDemo\main.c > CMakeFiles\JniDemo.dir\main.c.i

CMakeFiles/JniDemo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/JniDemo.dir/main.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\JniDemo\main.c -o CMakeFiles\JniDemo.dir\main.c.s

CMakeFiles/JniDemo.dir/main.c.obj.requires:

.PHONY : CMakeFiles/JniDemo.dir/main.c.obj.requires

CMakeFiles/JniDemo.dir/main.c.obj.provides: CMakeFiles/JniDemo.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\JniDemo.dir\build.make CMakeFiles/JniDemo.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/JniDemo.dir/main.c.obj.provides

CMakeFiles/JniDemo.dir/main.c.obj.provides.build: CMakeFiles/JniDemo.dir/main.c.obj


# Object files for target JniDemo
JniDemo_OBJECTS = \
"CMakeFiles/JniDemo.dir/main.c.obj"

# External object files for target JniDemo
JniDemo_EXTERNAL_OBJECTS =

JniDemo.exe: CMakeFiles/JniDemo.dir/main.c.obj
JniDemo.exe: CMakeFiles/JniDemo.dir/build.make
JniDemo.exe: CMakeFiles/JniDemo.dir/linklibs.rsp
JniDemo.exe: CMakeFiles/JniDemo.dir/objects1.rsp
JniDemo.exe: CMakeFiles/JniDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\JniDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable JniDemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\JniDemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JniDemo.dir/build: JniDemo.exe

.PHONY : CMakeFiles/JniDemo.dir/build

CMakeFiles/JniDemo.dir/requires: CMakeFiles/JniDemo.dir/main.c.obj.requires

.PHONY : CMakeFiles/JniDemo.dir/requires

CMakeFiles/JniDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\JniDemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/JniDemo.dir/clean

CMakeFiles/JniDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\JniDemo E:\CLion\JniDemo E:\CLion\JniDemo\cmake-build-debug E:\CLion\JniDemo\cmake-build-debug E:\CLion\JniDemo\cmake-build-debug\CMakeFiles\JniDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JniDemo.dir/depend
