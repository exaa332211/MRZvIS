# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/studing/MRZVIS/Transporter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/studing/MRZVIS/Transporter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tranporter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tranporter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tranporter.dir/flags.make

CMakeFiles/Tranporter.dir/main.cpp.o: CMakeFiles/Tranporter.dir/flags.make
CMakeFiles/Tranporter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/studing/MRZVIS/Transporter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tranporter.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tranporter.dir/main.cpp.o -c /home/alexander/studing/MRZVIS/Transporter/main.cpp

CMakeFiles/Tranporter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tranporter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/studing/MRZVIS/Transporter/main.cpp > CMakeFiles/Tranporter.dir/main.cpp.i

CMakeFiles/Tranporter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tranporter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/studing/MRZVIS/Transporter/main.cpp -o CMakeFiles/Tranporter.dir/main.cpp.s

CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o: CMakeFiles/Tranporter.dir/flags.make
CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o: ../classes/implementations/BinDigit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/studing/MRZVIS/Transporter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o -c /home/alexander/studing/MRZVIS/Transporter/classes/implementations/BinDigit.cpp

CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/studing/MRZVIS/Transporter/classes/implementations/BinDigit.cpp > CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.i

CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/studing/MRZVIS/Transporter/classes/implementations/BinDigit.cpp -o CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.s

# Object files for target Tranporter
Tranporter_OBJECTS = \
"CMakeFiles/Tranporter.dir/main.cpp.o" \
"CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o"

# External object files for target Tranporter
Tranporter_EXTERNAL_OBJECTS =

Tranporter: CMakeFiles/Tranporter.dir/main.cpp.o
Tranporter: CMakeFiles/Tranporter.dir/classes/implementations/BinDigit.cpp.o
Tranporter: CMakeFiles/Tranporter.dir/build.make
Tranporter: CMakeFiles/Tranporter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexander/studing/MRZVIS/Transporter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Tranporter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tranporter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tranporter.dir/build: Tranporter

.PHONY : CMakeFiles/Tranporter.dir/build

CMakeFiles/Tranporter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tranporter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tranporter.dir/clean

CMakeFiles/Tranporter.dir/depend:
	cd /home/alexander/studing/MRZVIS/Transporter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/studing/MRZVIS/Transporter /home/alexander/studing/MRZVIS/Transporter /home/alexander/studing/MRZVIS/Transporter/cmake-build-debug /home/alexander/studing/MRZVIS/Transporter/cmake-build-debug /home/alexander/studing/MRZVIS/Transporter/cmake-build-debug/CMakeFiles/Tranporter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tranporter.dir/depend

