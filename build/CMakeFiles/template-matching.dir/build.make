# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arslanali/CLionProjects/template_matching_opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arslanali/CLionProjects/template_matching_opencv/build

# Include any dependencies generated for this target.
include CMakeFiles/template-matching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/template-matching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template-matching.dir/flags.make

CMakeFiles/template-matching.dir/src/template_matching.cpp.o: CMakeFiles/template-matching.dir/flags.make
CMakeFiles/template-matching.dir/src/template_matching.cpp.o: ../src/template_matching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arslanali/CLionProjects/template_matching_opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template-matching.dir/src/template_matching.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template-matching.dir/src/template_matching.cpp.o -c /home/arslanali/CLionProjects/template_matching_opencv/src/template_matching.cpp

CMakeFiles/template-matching.dir/src/template_matching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template-matching.dir/src/template_matching.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arslanali/CLionProjects/template_matching_opencv/src/template_matching.cpp > CMakeFiles/template-matching.dir/src/template_matching.cpp.i

CMakeFiles/template-matching.dir/src/template_matching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template-matching.dir/src/template_matching.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arslanali/CLionProjects/template_matching_opencv/src/template_matching.cpp -o CMakeFiles/template-matching.dir/src/template_matching.cpp.s

CMakeFiles/template-matching.dir/src/template_matching.cpp.o.requires:

.PHONY : CMakeFiles/template-matching.dir/src/template_matching.cpp.o.requires

CMakeFiles/template-matching.dir/src/template_matching.cpp.o.provides: CMakeFiles/template-matching.dir/src/template_matching.cpp.o.requires
	$(MAKE) -f CMakeFiles/template-matching.dir/build.make CMakeFiles/template-matching.dir/src/template_matching.cpp.o.provides.build
.PHONY : CMakeFiles/template-matching.dir/src/template_matching.cpp.o.provides

CMakeFiles/template-matching.dir/src/template_matching.cpp.o.provides.build: CMakeFiles/template-matching.dir/src/template_matching.cpp.o


# Object files for target template-matching
template__matching_OBJECTS = \
"CMakeFiles/template-matching.dir/src/template_matching.cpp.o"

# External object files for target template-matching
template__matching_EXTERNAL_OBJECTS =

template-matching: CMakeFiles/template-matching.dir/src/template_matching.cpp.o
template-matching: CMakeFiles/template-matching.dir/build.make
template-matching: /usr/lib/x86_64-linux-gnu/libarmadillo.so
template-matching: /usr/local/lib/libopencv_highgui.so.4.2.0
template-matching: /usr/local/lib/libopencv_ml.so.4.2.0
template-matching: /usr/local/lib/libopencv_stitching.so.4.2.0
template-matching: /usr/local/lib/libopencv_dnn.so.4.2.0
template-matching: /usr/local/lib/libopencv_gapi.so.4.2.0
template-matching: /usr/local/lib/libopencv_videoio.so.4.2.0
template-matching: /usr/local/lib/libopencv_video.so.4.2.0
template-matching: /usr/local/lib/libopencv_imgcodecs.so.4.2.0
template-matching: /usr/local/lib/libopencv_objdetect.so.4.2.0
template-matching: /usr/local/lib/libopencv_photo.so.4.2.0
template-matching: /usr/local/lib/libopencv_calib3d.so.4.2.0
template-matching: /usr/local/lib/libopencv_features2d.so.4.2.0
template-matching: /usr/local/lib/libopencv_flann.so.4.2.0
template-matching: /usr/local/lib/libopencv_imgproc.so.4.2.0
template-matching: /usr/local/lib/libopencv_core.so.4.2.0
template-matching: CMakeFiles/template-matching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arslanali/CLionProjects/template_matching_opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable template-matching"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template-matching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template-matching.dir/build: template-matching

.PHONY : CMakeFiles/template-matching.dir/build

CMakeFiles/template-matching.dir/requires: CMakeFiles/template-matching.dir/src/template_matching.cpp.o.requires

.PHONY : CMakeFiles/template-matching.dir/requires

CMakeFiles/template-matching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/template-matching.dir/cmake_clean.cmake
.PHONY : CMakeFiles/template-matching.dir/clean

CMakeFiles/template-matching.dir/depend:
	cd /home/arslanali/CLionProjects/template_matching_opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arslanali/CLionProjects/template_matching_opencv /home/arslanali/CLionProjects/template_matching_opencv /home/arslanali/CLionProjects/template_matching_opencv/build /home/arslanali/CLionProjects/template_matching_opencv/build /home/arslanali/CLionProjects/template_matching_opencv/build/CMakeFiles/template-matching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template-matching.dir/depend
