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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sf_share/blackjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_share/blackjack/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/judge_test.out.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/judge_test.out.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/judge_test.out.dir/flags.make

tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.o: tests/CMakeFiles/judge_test.out.dir/flags.make
tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.o: ../tests/judge_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_share/blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.o"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/judge_test.out.dir/judge_test.cpp.o -c /media/sf_share/blackjack/tests/judge_test.cpp

tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/judge_test.out.dir/judge_test.cpp.i"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_share/blackjack/tests/judge_test.cpp > CMakeFiles/judge_test.out.dir/judge_test.cpp.i

tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/judge_test.out.dir/judge_test.cpp.s"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_share/blackjack/tests/judge_test.cpp -o CMakeFiles/judge_test.out.dir/judge_test.cpp.s

tests/CMakeFiles/judge_test.out.dir/main.cpp.o: tests/CMakeFiles/judge_test.out.dir/flags.make
tests/CMakeFiles/judge_test.out.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_share/blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/judge_test.out.dir/main.cpp.o"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/judge_test.out.dir/main.cpp.o -c /media/sf_share/blackjack/tests/main.cpp

tests/CMakeFiles/judge_test.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/judge_test.out.dir/main.cpp.i"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_share/blackjack/tests/main.cpp > CMakeFiles/judge_test.out.dir/main.cpp.i

tests/CMakeFiles/judge_test.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/judge_test.out.dir/main.cpp.s"
	cd /media/sf_share/blackjack/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_share/blackjack/tests/main.cpp -o CMakeFiles/judge_test.out.dir/main.cpp.s

# Object files for target judge_test.out
judge_test_out_OBJECTS = \
"CMakeFiles/judge_test.out.dir/judge_test.cpp.o" \
"CMakeFiles/judge_test.out.dir/main.cpp.o"

# External object files for target judge_test.out
judge_test_out_EXTERNAL_OBJECTS =

tests/judge_test.out: tests/CMakeFiles/judge_test.out.dir/judge_test.cpp.o
tests/judge_test.out: tests/CMakeFiles/judge_test.out.dir/main.cpp.o
tests/judge_test.out: tests/CMakeFiles/judge_test.out.dir/build.make
tests/judge_test.out: src/libjudge.a
tests/judge_test.out: tests/CMakeFiles/judge_test.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_share/blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable judge_test.out"
	cd /media/sf_share/blackjack/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/judge_test.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/judge_test.out.dir/build: tests/judge_test.out

.PHONY : tests/CMakeFiles/judge_test.out.dir/build

tests/CMakeFiles/judge_test.out.dir/clean:
	cd /media/sf_share/blackjack/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/judge_test.out.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/judge_test.out.dir/clean

tests/CMakeFiles/judge_test.out.dir/depend:
	cd /media/sf_share/blackjack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_share/blackjack /media/sf_share/blackjack/tests /media/sf_share/blackjack/build /media/sf_share/blackjack/build/tests /media/sf_share/blackjack/build/tests/CMakeFiles/judge_test.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/judge_test.out.dir/depend

