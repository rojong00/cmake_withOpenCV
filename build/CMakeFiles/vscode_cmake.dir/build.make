# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\vsStudioWorkspace\vscode_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\vsStudioWorkspace\vscode_cmake\build

# Include any dependencies generated for this target.
include CMakeFiles/vscode_cmake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vscode_cmake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vscode_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vscode_cmake.dir/flags.make

CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj: CMakeFiles/vscode_cmake.dir/flags.make
CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj: CMakeFiles/vscode_cmake.dir/includes_CXX.rsp
CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj: D:/vsStudioWorkspace/vscode_cmake/source/histogram.cpp
CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj: CMakeFiles/vscode_cmake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\vsStudioWorkspace\vscode_cmake\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj -MF CMakeFiles\vscode_cmake.dir\source\histogram.cpp.obj.d -o CMakeFiles\vscode_cmake.dir\source\histogram.cpp.obj -c D:\vsStudioWorkspace\vscode_cmake\source\histogram.cpp

CMakeFiles/vscode_cmake.dir/source/histogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vscode_cmake.dir/source/histogram.cpp.i"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\vsStudioWorkspace\vscode_cmake\source\histogram.cpp > CMakeFiles\vscode_cmake.dir\source\histogram.cpp.i

CMakeFiles/vscode_cmake.dir/source/histogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vscode_cmake.dir/source/histogram.cpp.s"
	C:\MinGw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\vsStudioWorkspace\vscode_cmake\source\histogram.cpp -o CMakeFiles\vscode_cmake.dir\source\histogram.cpp.s

# Object files for target vscode_cmake
vscode_cmake_OBJECTS = \
"CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj"

# External object files for target vscode_cmake
vscode_cmake_EXTERNAL_OBJECTS =

D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: CMakeFiles/vscode_cmake.dir/source/histogram.cpp.obj
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: CMakeFiles/vscode_cmake.dir/build.make
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: D:/vsStudioWorkspace/vscode_cmake/lib/opencv/build/x64/vc16/lib/opencv_world480.lib
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: D:/vsStudioWorkspace/vscode_cmake/lib/opencv/build/x64/vc16/lib/opencv_world480d.lib
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: CMakeFiles/vscode_cmake.dir/linkLibs.rsp
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: CMakeFiles/vscode_cmake.dir/objects1.rsp
D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe: CMakeFiles/vscode_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\vsStudioWorkspace\vscode_cmake\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D:\vsStudioWorkspace\vscode_cmake\output\vscode_cmake.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vscode_cmake.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vscode_cmake.dir/build: D:/vsStudioWorkspace/vscode_cmake/output/vscode_cmake.exe
.PHONY : CMakeFiles/vscode_cmake.dir/build

CMakeFiles/vscode_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vscode_cmake.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vscode_cmake.dir/clean

CMakeFiles/vscode_cmake.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\vsStudioWorkspace\vscode_cmake D:\vsStudioWorkspace\vscode_cmake D:\vsStudioWorkspace\vscode_cmake\build D:\vsStudioWorkspace\vscode_cmake\build D:\vsStudioWorkspace\vscode_cmake\build\CMakeFiles\vscode_cmake.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vscode_cmake.dir/depend

