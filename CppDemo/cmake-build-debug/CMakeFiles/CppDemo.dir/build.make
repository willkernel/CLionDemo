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
CMAKE_SOURCE_DIR = E:\CLion\CppDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\CppDemo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CppDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CppDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppDemo.dir/flags.make

CMakeFiles/CppDemo.dir/main.cpp.obj: CMakeFiles/CppDemo.dir/flags.make
CMakeFiles/CppDemo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\CppDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppDemo.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CppDemo.dir\main.cpp.obj -c E:\CLion\CppDemo\main.cpp

CMakeFiles/CppDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppDemo.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CLion\CppDemo\main.cpp > CMakeFiles\CppDemo.dir\main.cpp.i

CMakeFiles/CppDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppDemo.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CLion\CppDemo\main.cpp -o CMakeFiles\CppDemo.dir\main.cpp.s

CMakeFiles/CppDemo.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/CppDemo.dir/main.cpp.obj.requires

CMakeFiles/CppDemo.dir/main.cpp.obj.provides: CMakeFiles/CppDemo.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CppDemo.dir\build.make CMakeFiles/CppDemo.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CppDemo.dir/main.cpp.obj.provides

CMakeFiles/CppDemo.dir/main.cpp.obj.provides.build: CMakeFiles/CppDemo.dir/main.cpp.obj


# Object files for target CppDemo
CppDemo_OBJECTS = \
"CMakeFiles/CppDemo.dir/main.cpp.obj"

# External object files for target CppDemo
CppDemo_EXTERNAL_OBJECTS =

CppDemo.exe: CMakeFiles/CppDemo.dir/main.cpp.obj
CppDemo.exe: CMakeFiles/CppDemo.dir/build.make
CppDemo.exe: CMakeFiles/CppDemo.dir/linklibs.rsp
CppDemo.exe: CMakeFiles/CppDemo.dir/objects1.rsp
CppDemo.exe: CMakeFiles/CppDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\CppDemo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CppDemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CppDemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppDemo.dir/build: CppDemo.exe

.PHONY : CMakeFiles/CppDemo.dir/build

CMakeFiles/CppDemo.dir/requires: CMakeFiles/CppDemo.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/CppDemo.dir/requires

CMakeFiles/CppDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CppDemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CppDemo.dir/clean

CMakeFiles/CppDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\CppDemo E:\CLion\CppDemo E:\CLion\CppDemo\cmake-build-debug E:\CLion\CppDemo\cmake-build-debug E:\CLion\CppDemo\cmake-build-debug\CMakeFiles\CppDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CppDemo.dir/depend
