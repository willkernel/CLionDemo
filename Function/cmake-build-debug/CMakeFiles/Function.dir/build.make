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
CMAKE_SOURCE_DIR = E:\willkernel\CLionDemo\Function

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\willkernel\CLionDemo\Function\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Function.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Function.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Function.dir/flags.make

CMakeFiles/Function.dir/main.cpp.obj: CMakeFiles/Function.dir/flags.make
CMakeFiles/Function.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\willkernel\CLionDemo\Function\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Function.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Function.dir\main.cpp.obj -c E:\willkernel\CLionDemo\Function\main.cpp

CMakeFiles/Function.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Function.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\willkernel\CLionDemo\Function\main.cpp > CMakeFiles\Function.dir\main.cpp.i

CMakeFiles/Function.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Function.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\willkernel\CLionDemo\Function\main.cpp -o CMakeFiles\Function.dir\main.cpp.s

CMakeFiles/Function.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Function.dir/main.cpp.obj.requires

CMakeFiles/Function.dir/main.cpp.obj.provides: CMakeFiles/Function.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Function.dir\build.make CMakeFiles/Function.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Function.dir/main.cpp.obj.provides

CMakeFiles/Function.dir/main.cpp.obj.provides.build: CMakeFiles/Function.dir/main.cpp.obj


# Object files for target Function
Function_OBJECTS = \
"CMakeFiles/Function.dir/main.cpp.obj"

# External object files for target Function
Function_EXTERNAL_OBJECTS =

Function.exe: CMakeFiles/Function.dir/main.cpp.obj
Function.exe: CMakeFiles/Function.dir/build.make
Function.exe: CMakeFiles/Function.dir/linklibs.rsp
Function.exe: CMakeFiles/Function.dir/objects1.rsp
Function.exe: CMakeFiles/Function.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\willkernel\CLionDemo\Function\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Function.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Function.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Function.dir/build: Function.exe

.PHONY : CMakeFiles/Function.dir/build

CMakeFiles/Function.dir/requires: CMakeFiles/Function.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Function.dir/requires

CMakeFiles/Function.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Function.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Function.dir/clean

CMakeFiles/Function.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\willkernel\CLionDemo\Function E:\willkernel\CLionDemo\Function E:\willkernel\CLionDemo\Function\cmake-build-debug E:\willkernel\CLionDemo\Function\cmake-build-debug E:\willkernel\CLionDemo\Function\cmake-build-debug\CMakeFiles\Function.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Function.dir/depend
