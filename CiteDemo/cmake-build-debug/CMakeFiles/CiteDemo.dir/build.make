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
CMAKE_SOURCE_DIR = E:\willkernel\CLionDemo\CiteDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CiteDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CiteDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CiteDemo.dir/flags.make

CMakeFiles/CiteDemo.dir/main.cpp.obj: CMakeFiles/CiteDemo.dir/flags.make
CMakeFiles/CiteDemo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CiteDemo.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CiteDemo.dir\main.cpp.obj -c E:\willkernel\CLionDemo\CiteDemo\main.cpp

CMakeFiles/CiteDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CiteDemo.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\willkernel\CLionDemo\CiteDemo\main.cpp > CMakeFiles\CiteDemo.dir\main.cpp.i

CMakeFiles/CiteDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CiteDemo.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\willkernel\CLionDemo\CiteDemo\main.cpp -o CMakeFiles\CiteDemo.dir\main.cpp.s

CMakeFiles/CiteDemo.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/CiteDemo.dir/main.cpp.obj.requires

CMakeFiles/CiteDemo.dir/main.cpp.obj.provides: CMakeFiles/CiteDemo.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CiteDemo.dir\build.make CMakeFiles/CiteDemo.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CiteDemo.dir/main.cpp.obj.provides

CMakeFiles/CiteDemo.dir/main.cpp.obj.provides.build: CMakeFiles/CiteDemo.dir/main.cpp.obj


# Object files for target CiteDemo
CiteDemo_OBJECTS = \
"CMakeFiles/CiteDemo.dir/main.cpp.obj"

# External object files for target CiteDemo
CiteDemo_EXTERNAL_OBJECTS =

CiteDemo.exe: CMakeFiles/CiteDemo.dir/main.cpp.obj
CiteDemo.exe: CMakeFiles/CiteDemo.dir/build.make
CiteDemo.exe: CMakeFiles/CiteDemo.dir/linklibs.rsp
CiteDemo.exe: CMakeFiles/CiteDemo.dir/objects1.rsp
CiteDemo.exe: CMakeFiles/CiteDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CiteDemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CiteDemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CiteDemo.dir/build: CiteDemo.exe

.PHONY : CMakeFiles/CiteDemo.dir/build

CMakeFiles/CiteDemo.dir/requires: CMakeFiles/CiteDemo.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/CiteDemo.dir/requires

CMakeFiles/CiteDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CiteDemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CiteDemo.dir/clean

CMakeFiles/CiteDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\willkernel\CLionDemo\CiteDemo E:\willkernel\CLionDemo\CiteDemo E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug E:\willkernel\CLionDemo\CiteDemo\cmake-build-debug\CMakeFiles\CiteDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CiteDemo.dir/depend

