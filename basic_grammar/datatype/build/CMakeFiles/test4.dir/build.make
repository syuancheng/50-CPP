# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build

# Include any dependencies generated for this target.
include CMakeFiles/test4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test4.dir/flags.make

CMakeFiles/test4.dir/test4.cpp.o: CMakeFiles/test4.dir/flags.make
CMakeFiles/test4.dir/test4.cpp.o: /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/test4.cpp
CMakeFiles/test4.dir/test4.cpp.o: CMakeFiles/test4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test4.dir/test4.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test4.dir/test4.cpp.o -MF CMakeFiles/test4.dir/test4.cpp.o.d -o CMakeFiles/test4.dir/test4.cpp.o -c /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/test4.cpp

CMakeFiles/test4.dir/test4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test4.dir/test4.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/test4.cpp > CMakeFiles/test4.dir/test4.cpp.i

CMakeFiles/test4.dir/test4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test4.dir/test4.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/test4.cpp -o CMakeFiles/test4.dir/test4.cpp.s

# Object files for target test4
test4_OBJECTS = \
"CMakeFiles/test4.dir/test4.cpp.o"

# External object files for target test4
test4_EXTERNAL_OBJECTS =

test4: CMakeFiles/test4.dir/test4.cpp.o
test4: CMakeFiles/test4.dir/build.make
test4: CMakeFiles/test4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test4.dir/build: test4
.PHONY : CMakeFiles/test4.dir/build

CMakeFiles/test4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test4.dir/clean

CMakeFiles/test4.dir/depend:
	cd /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build /Users/siyuancheng/Documents/cpp_workspace/50-CPP/basic_grammar/datatype/build/CMakeFiles/test4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test4.dir/depend

