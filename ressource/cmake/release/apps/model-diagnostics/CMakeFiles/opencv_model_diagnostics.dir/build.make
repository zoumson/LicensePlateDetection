# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/opencv/release

# Include any dependencies generated for this target.
include apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/depend.make

# Include the progress variables for this target.
include apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/progress.make

# Include the compile flags for this target's objects.
include apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/flags.make

apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o: apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/flags.make
apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o: ../apps/model-diagnostics/model_diagnostics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o"
	cd /opt/opencv/release/apps/model-diagnostics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o -c /opt/opencv/apps/model-diagnostics/model_diagnostics.cpp

apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.i"
	cd /opt/opencv/release/apps/model-diagnostics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv/apps/model-diagnostics/model_diagnostics.cpp > CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.i

apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.s"
	cd /opt/opencv/release/apps/model-diagnostics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv/apps/model-diagnostics/model_diagnostics.cpp -o CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.s

# Object files for target opencv_model_diagnostics
opencv_model_diagnostics_OBJECTS = \
"CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o"

# External object files for target opencv_model_diagnostics
opencv_model_diagnostics_EXTERNAL_OBJECTS =

bin/opencv_model_diagnostics: apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/model_diagnostics.cpp.o
bin/opencv_model_diagnostics: apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/build.make
bin/opencv_model_diagnostics: lib/libopencv_dnn.so.4.5.2
bin/opencv_model_diagnostics: lib/libopencv_imgproc.so.4.5.2
bin/opencv_model_diagnostics: lib/libopencv_core.so.4.5.2
bin/opencv_model_diagnostics: apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/opencv_model_diagnostics"
	cd /opt/opencv/release/apps/model-diagnostics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_model_diagnostics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/build: bin/opencv_model_diagnostics

.PHONY : apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/build

apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/clean:
	cd /opt/opencv/release/apps/model-diagnostics && $(CMAKE_COMMAND) -P CMakeFiles/opencv_model_diagnostics.dir/cmake_clean.cmake
.PHONY : apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/clean

apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/depend:
	cd /opt/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/opencv /opt/opencv/apps/model-diagnostics /opt/opencv/release /opt/opencv/release/apps/model-diagnostics /opt/opencv/release/apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/model-diagnostics/CMakeFiles/opencv_model_diagnostics.dir/depend

