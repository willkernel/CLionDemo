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
CMAKE_SOURCE_DIR = E:\willkernel\CLionDemo\StringDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\willkernel\CLionDemo\StringDemo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StringDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StringDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringDemo.dir/flags.make

CMakeFiles/StringDemo.dir/main.cpp.obj: CMakeFiles/StringDemo.dir/flags.make
CMakeFiles/StringDemo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\willkernel\CLionDemo\StringDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringDemo.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StringDemo.dir\main.cpp.obj -c E:\willkernel\CLionDemo\StringDemo\main.cpp

CMakeFiles/StringDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringDemo.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\willkernel\CLionDemo\StringDemo\main.cpp > CMakeFiles\StringDemo.dir\main.cpp.i

CMakeFiles/StringDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringDemo.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\willkernel\CLionDemo\StringDemo\main.cpp -o CMakeFiles\StringDemo.dir\main.cpp.s

CMakeFiles/StringDemo.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/StringDemo.dir/main.cpp.obj.requires

CMakeFiles/StringDemo.dir/main.cpp.obj.provides: CMakeFiles/StringDemo.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\StringDemo.dir\build.make CMakeFiles/StringDemo.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/StringDemo.dir/main.cpp.obj.provides

CMakeFiles/StringDemo.dir/main.cpp.obj.provides.build: CMakeFiles/StringDemo.dir/main.cpp.obj


# Object files for target StringDemo
StringDemo_OBJECTS = \
"CMakeFiles/StringDemo.dir/main.cpp.obj"

# External object files for target StringDemo
StringDemo_EXTERNAL_OBJECTS =

StringDemo.exe: CMakeFiles/StringDemo.dir/main.cpp.obj
StringDemo.exe: CMakeFiles/StringDemo.dir/build.make
StringDemo.exe: CMakeFiles/StringDemo.dir/linklibs.rsp
StringDemo.exe: CMakeFiles/StringDemo.dir/objects1.rsp
StringDemo.exe: CMakeFiles/StringDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\willkernel\CLionDemo\StringDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StringDemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StringDemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringDemo.dir/build: StringDemo.exe

.PHONY : CMakeFiles/StringDemo.dir/build

CMakeFiles/StringDemo.dir/requires: CMakeFiles/StringDemo.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/StringDemo.dir/requires

CMakeFiles/StringDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StringDemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StringDemo.dir/clean

CMakeFiles/StringDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\willkernel\CLionDemo\StringDemo E:\willkernel\CLionDemo\StringDemo E:\willkernel\CLionDemo\StringDemo\cmake-build-debug E:\willkernel\CLionDemo\StringDemo\cmake-build-debug E:\willkernel\CLionDemo\StringDemo\cmake-build-debug\CMakeFiles\StringDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StringDemo.dir/depend

