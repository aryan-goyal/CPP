# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Statistics_Range_and_Mode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Statistics_Range_and_Mode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Statistics_Range_and_Mode.dir/flags.make

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj: CMakeFiles/Statistics_Range_and_Mode.dir/flags.make
CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj: ../Mode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Statistics_Range_and_Mode.dir\Mode.cpp.obj -c "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\Mode.cpp"

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\Mode.cpp" > CMakeFiles\Statistics_Range_and_Mode.dir\Mode.cpp.i

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\Mode.cpp" -o CMakeFiles\Statistics_Range_and_Mode.dir\Mode.cpp.s

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.requires:

.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.requires

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.provides: CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Statistics_Range_and_Mode.dir\build.make CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.provides.build
.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.provides

CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.provides.build: CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj


# Object files for target Statistics_Range_and_Mode
Statistics_Range_and_Mode_OBJECTS = \
"CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj"

# External object files for target Statistics_Range_and_Mode
Statistics_Range_and_Mode_EXTERNAL_OBJECTS =

Statistics_Range_and_Mode.exe: CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj
Statistics_Range_and_Mode.exe: CMakeFiles/Statistics_Range_and_Mode.dir/build.make
Statistics_Range_and_Mode.exe: CMakeFiles/Statistics_Range_and_Mode.dir/linklibs.rsp
Statistics_Range_and_Mode.exe: CMakeFiles/Statistics_Range_and_Mode.dir/objects1.rsp
Statistics_Range_and_Mode.exe: CMakeFiles/Statistics_Range_and_Mode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Statistics_Range_and_Mode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Statistics_Range_and_Mode.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Statistics_Range_and_Mode.dir/build: Statistics_Range_and_Mode.exe

.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/build

CMakeFiles/Statistics_Range_and_Mode.dir/requires: CMakeFiles/Statistics_Range_and_Mode.dir/Mode.cpp.obj.requires

.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/requires

CMakeFiles/Statistics_Range_and_Mode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Statistics_Range_and_Mode.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/clean

CMakeFiles/Statistics_Range_and_Mode.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode" "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode" "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug" "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug" "C:\Users\aryan\Desktop\Workspace\Statistics Range and Mode\cmake-build-debug\CMakeFiles\Statistics_Range_and_Mode.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Statistics_Range_and_Mode.dir/depend

