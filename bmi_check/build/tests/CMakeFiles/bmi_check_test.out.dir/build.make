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
CMAKE_SOURCE_DIR = /media/sf_share/bmi_check

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_share/bmi_check/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/bmi_check_test.out.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/bmi_check_test.out.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/bmi_check_test.out.dir/flags.make

tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o: tests/CMakeFiles/bmi_check_test.out.dir/flags.make
tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o: ../tests/bmi_check_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_share/bmi_check/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o -c /media/sf_share/bmi_check/tests/bmi_check_test.cpp

tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.i"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_share/bmi_check/tests/bmi_check_test.cpp > CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.i

tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.s"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_share/bmi_check/tests/bmi_check_test.cpp -o CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.s

tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.o: tests/CMakeFiles/bmi_check_test.out.dir/flags.make
tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_share/bmi_check/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.o"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bmi_check_test.out.dir/main.cpp.o -c /media/sf_share/bmi_check/tests/main.cpp

tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bmi_check_test.out.dir/main.cpp.i"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_share/bmi_check/tests/main.cpp > CMakeFiles/bmi_check_test.out.dir/main.cpp.i

tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bmi_check_test.out.dir/main.cpp.s"
	cd /media/sf_share/bmi_check/build/tests && /usr/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_share/bmi_check/tests/main.cpp -o CMakeFiles/bmi_check_test.out.dir/main.cpp.s

# Object files for target bmi_check_test.out
bmi_check_test_out_OBJECTS = \
"CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o" \
"CMakeFiles/bmi_check_test.out.dir/main.cpp.o"

# External object files for target bmi_check_test.out
bmi_check_test_out_EXTERNAL_OBJECTS =

tests/bmi_check_test.out: tests/CMakeFiles/bmi_check_test.out.dir/bmi_check_test.cpp.o
tests/bmi_check_test.out: tests/CMakeFiles/bmi_check_test.out.dir/main.cpp.o
tests/bmi_check_test.out: tests/CMakeFiles/bmi_check_test.out.dir/build.make
tests/bmi_check_test.out: src/libbmi_check.a
tests/bmi_check_test.out: tests/CMakeFiles/bmi_check_test.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_share/bmi_check/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bmi_check_test.out"
	cd /media/sf_share/bmi_check/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bmi_check_test.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/bmi_check_test.out.dir/build: tests/bmi_check_test.out

.PHONY : tests/CMakeFiles/bmi_check_test.out.dir/build

tests/CMakeFiles/bmi_check_test.out.dir/clean:
	cd /media/sf_share/bmi_check/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/bmi_check_test.out.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/bmi_check_test.out.dir/clean

tests/CMakeFiles/bmi_check_test.out.dir/depend:
	cd /media/sf_share/bmi_check/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_share/bmi_check /media/sf_share/bmi_check/tests /media/sf_share/bmi_check/build /media/sf_share/bmi_check/build/tests /media/sf_share/bmi_check/build/tests/CMakeFiles/bmi_check_test.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/bmi_check_test.out.dir/depend

