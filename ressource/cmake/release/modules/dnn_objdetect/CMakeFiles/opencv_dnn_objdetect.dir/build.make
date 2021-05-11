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
include modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/depend.make

# Include the progress variables for this target.
include modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/progress.make

# Include the compile flags for this target's objects.
include modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/flags.make

modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o: modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/flags.make
modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o: /opt/opencv_contrib/modules/dnn_objdetect/src/core_detect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o"
	cd /opt/opencv/release/modules/dnn_objdetect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o -c /opt/opencv_contrib/modules/dnn_objdetect/src/core_detect.cpp

modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.i"
	cd /opt/opencv/release/modules/dnn_objdetect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/dnn_objdetect/src/core_detect.cpp > CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.i

modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.s"
	cd /opt/opencv/release/modules/dnn_objdetect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/dnn_objdetect/src/core_detect.cpp -o CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.s

# Object files for target opencv_dnn_objdetect
opencv_dnn_objdetect_OBJECTS = \
"CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o"

# External object files for target opencv_dnn_objdetect
opencv_dnn_objdetect_EXTERNAL_OBJECTS =

lib/libopencv_dnn_objdetect.so.4.5.2: modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/src/core_detect.cpp.o
lib/libopencv_dnn_objdetect.so.4.5.2: modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/build.make
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_dnn.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_highgui.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_videoio.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_imgcodecs.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_imgproc.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: lib/libopencv_core.so.4.5.2
lib/libopencv_dnn_objdetect.so.4.5.2: modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libopencv_dnn_objdetect.so"
	cd /opt/opencv/release/modules/dnn_objdetect && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_dnn_objdetect.dir/link.txt --verbose=$(VERBOSE)
	cd /opt/opencv/release/modules/dnn_objdetect && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libopencv_dnn_objdetect.so.4.5.2 ../../lib/libopencv_dnn_objdetect.so.4.5 ../../lib/libopencv_dnn_objdetect.so

lib/libopencv_dnn_objdetect.so.4.5: lib/libopencv_dnn_objdetect.so.4.5.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_dnn_objdetect.so.4.5

lib/libopencv_dnn_objdetect.so: lib/libopencv_dnn_objdetect.so.4.5.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_dnn_objdetect.so

# Rule to build all files generated by this target.
modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/build: lib/libopencv_dnn_objdetect.so

.PHONY : modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/build

modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/clean:
	cd /opt/opencv/release/modules/dnn_objdetect && $(CMAKE_COMMAND) -P CMakeFiles/opencv_dnn_objdetect.dir/cmake_clean.cmake
.PHONY : modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/clean

modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/depend:
	cd /opt/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/opencv /opt/opencv_contrib/modules/dnn_objdetect /opt/opencv/release /opt/opencv/release/modules/dnn_objdetect /opt/opencv/release/modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/dnn_objdetect/CMakeFiles/opencv_dnn_objdetect.dir/depend

