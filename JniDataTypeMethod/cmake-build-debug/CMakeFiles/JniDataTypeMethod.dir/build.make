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
CMAKE_SOURCE_DIR = E:\CLion\JniDataTypeMethod

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\JniDataTypeMethod\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JniDataTypeMethod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JniDataTypeMethod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JniDataTypeMethod.dir/flags.make

CMakeFiles/JniDataTypeMethod.dir/main.c.obj: CMakeFiles/JniDataTypeMethod.dir/flags.make
CMakeFiles/JniDataTypeMethod.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\JniDataTypeMethod\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/JniDataTypeMethod.dir/main.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\JniDataTypeMethod.dir\main.c.obj   -c E:\CLion\JniDataTypeMethod\main.c

CMakeFiles/JniDataTypeMethod.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/JniDataTypeMethod.dir/main.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\JniDataTypeMethod\main.c > CMakeFiles\JniDataTypeMethod.dir\main.c.i

CMakeFiles/JniDataTypeMethod.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/JniDataTypeMethod.dir/main.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\JniDataTypeMethod\main.c -o CMakeFiles\JniDataTypeMethod.dir\main.c.s

CMakeFiles/JniDataTypeMethod.dir/main.c.obj.requires:

.PHONY : CMakeFiles/JniDataTypeMethod.dir/main.c.obj.requires

CMakeFiles/JniDataTypeMethod.dir/main.c.obj.provides: CMakeFiles/JniDataTypeMethod.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\JniDataTypeMethod.dir\build.make CMakeFiles/JniDataTypeMethod.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/JniDataTypeMethod.dir/main.c.obj.provides

CMakeFiles/JniDataTypeMethod.dir/main.c.obj.provides.build: CMakeFiles/JniDataTypeMethod.dir/main.c.obj


# Object files for target JniDataTypeMethod
JniDataTypeMethod_OBJECTS = \
"CMakeFiles/JniDataTypeMethod.dir/main.c.obj"

# External object files for target JniDataTypeMethod
JniDataTypeMethod_EXTERNAL_OBJECTS =

JniDataTypeMethod.exe: CMakeFiles/JniDataTypeMethod.dir/main.c.obj
JniDataTypeMethod.exe: CMakeFiles/JniDataTypeMethod.dir/build.make
JniDataTypeMethod.exe: CMakeFiles/JniDataTypeMethod.dir/linklibs.rsp
JniDataTypeMethod.exe: CMakeFiles/JniDataTypeMethod.dir/objects1.rsp
JniDataTypeMethod.exe: CMakeFiles/JniDataTypeMethod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\JniDataTypeMethod\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable JniDataTypeMethod.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\JniDataTypeMethod.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JniDataTypeMethod.dir/build: JniDataTypeMethod.exe

.PHONY : CMakeFiles/JniDataTypeMethod.dir/build

CMakeFiles/JniDataTypeMethod.dir/requires: CMakeFiles/JniDataTypeMethod.dir/main.c.obj.requires

.PHONY : CMakeFiles/JniDataTypeMethod.dir/requires

CMakeFiles/JniDataTypeMethod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\JniDataTypeMethod.dir\cmake_clean.cmake
.PHONY : CMakeFiles/JniDataTypeMethod.dir/clean

CMakeFiles/JniDataTypeMethod.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\JniDataTypeMethod E:\CLion\JniDataTypeMethod E:\CLion\JniDataTypeMethod\cmake-build-debug E:\CLion\JniDataTypeMethod\cmake-build-debug E:\CLion\JniDataTypeMethod\cmake-build-debug\CMakeFiles\JniDataTypeMethod.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JniDataTypeMethod.dir/depend

