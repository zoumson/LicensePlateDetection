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
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend.make

# Include the progress variables for this target.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/progress.make

# Include the compile flags for this target's objects.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o: /opt/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o -c /opt/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o: /opt/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o -c /opt/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o: /opt/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o -c /opt/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o: /opt/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o -c /opt/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o: /opt/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o -c /opt/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp > CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s"
	cd /opt/opencv/release/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp -o CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s

# Object files for target opencv_bgsegm
opencv_bgsegm_OBJECTS = \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o"

# External object files for target opencv_bgsegm
opencv_bgsegm_EXTERNAL_OBJECTS =

lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build.make
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_video.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_dnn.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_calib3d.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_features2d.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_flann.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_imgproc.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: lib/libopencv_core.so.4.5.2
lib/libopencv_bgsegm.so.4.5.2: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/opencv/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../lib/libopencv_bgsegm.so"
	cd /opt/opencv/release/modules/bgsegm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_bgsegm.dir/link.txt --verbose=$(VERBOSE)
	cd /opt/opencv/release/modules/bgsegm && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libopencv_bgsegm.so.4.5.2 ../../lib/libopencv_bgsegm.so.4.5 ../../lib/libopencv_bgsegm.so

lib/libopencv_bgsegm.so.4.5: lib/libopencv_bgsegm.so.4.5.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_bgsegm.so.4.5

lib/libopencv_bgsegm.so: lib/libopencv_bgsegm.so.4.5.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_bgsegm.so

# Rule to build all files generated by this target.
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build: lib/libopencv_bgsegm.so

.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/clean:
	cd /opt/opencv/release/modules/bgsegm && $(CMAKE_COMMAND) -P CMakeFiles/opencv_bgsegm.dir/cmake_clean.cmake
.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/clean

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend:
	cd /opt/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/opencv /opt/opencv_contrib/modules/bgsegm /opt/opencv/release /opt/opencv/release/modules/bgsegm /opt/opencv/release/modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend

