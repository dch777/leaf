# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dchanana/Projects/leaf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dchanana/Projects/leaf/build

# Include any dependencies generated for this target.
include CMakeFiles/lcc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lcc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lcc.dir/flags.make

CMakeFiles/lcc.dir/src/lexer.cpp.o: CMakeFiles/lcc.dir/flags.make
CMakeFiles/lcc.dir/src/lexer.cpp.o: ../src/lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dchanana/Projects/leaf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lcc.dir/src/lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lcc.dir/src/lexer.cpp.o -c /home/dchanana/Projects/leaf/src/lexer.cpp

CMakeFiles/lcc.dir/src/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lcc.dir/src/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dchanana/Projects/leaf/src/lexer.cpp > CMakeFiles/lcc.dir/src/lexer.cpp.i

CMakeFiles/lcc.dir/src/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lcc.dir/src/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dchanana/Projects/leaf/src/lexer.cpp -o CMakeFiles/lcc.dir/src/lexer.cpp.s

# Object files for target lcc
lcc_OBJECTS = \
"CMakeFiles/lcc.dir/src/lexer.cpp.o"

# External object files for target lcc
lcc_EXTERNAL_OBJECTS =

lcc: CMakeFiles/lcc.dir/src/lexer.cpp.o
lcc: CMakeFiles/lcc.dir/build.make
lcc: CMakeFiles/lcc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dchanana/Projects/leaf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lcc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lcc.dir/build: lcc

.PHONY : CMakeFiles/lcc.dir/build

CMakeFiles/lcc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lcc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lcc.dir/clean

CMakeFiles/lcc.dir/depend:
	cd /home/dchanana/Projects/leaf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dchanana/Projects/leaf /home/dchanana/Projects/leaf /home/dchanana/Projects/leaf/build /home/dchanana/Projects/leaf/build /home/dchanana/Projects/leaf/build/CMakeFiles/lcc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lcc.dir/depend

