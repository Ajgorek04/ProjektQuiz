# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Coding\ProjektQuiz\Qt\QuizGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Coding\ProjektQuiz\build

# Utility rule file for tests_autogen.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/tests_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests_autogen.dir/progress.make

tests/CMakeFiles/tests_autogen: tests/tests_autogen/timestamp

tests/tests_autogen/timestamp: C:/Qt/6.9.0/mingw_64/bin/moc.exe
tests/tests_autogen/timestamp: tests/CMakeFiles/tests_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=F:\Coding\ProjektQuiz\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target tests"
	cd /d F:\Coding\ProjektQuiz\build\tests && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen F:/Coding/ProjektQuiz/build/tests/CMakeFiles/tests_autogen.dir/AutogenInfo.json Debug
	cd /d F:\Coding\ProjektQuiz\build\tests && "C:\Program Files\CMake\bin\cmake.exe" -E touch F:/Coding/ProjektQuiz/build/tests/tests_autogen/timestamp

tests/CMakeFiles/tests_autogen.dir/codegen:
.PHONY : tests/CMakeFiles/tests_autogen.dir/codegen

tests_autogen: tests/CMakeFiles/tests_autogen
tests_autogen: tests/tests_autogen/timestamp
tests_autogen: tests/CMakeFiles/tests_autogen.dir/build.make
.PHONY : tests_autogen

# Rule to build all files generated by this target.
tests/CMakeFiles/tests_autogen.dir/build: tests_autogen
.PHONY : tests/CMakeFiles/tests_autogen.dir/build

tests/CMakeFiles/tests_autogen.dir/clean:
	cd /d F:\Coding\ProjektQuiz\build\tests && $(CMAKE_COMMAND) -P CMakeFiles\tests_autogen.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests_autogen.dir/clean

tests/CMakeFiles/tests_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Coding\ProjektQuiz\Qt\QuizGame F:\Coding\ProjektQuiz\tests F:\Coding\ProjektQuiz\build F:\Coding\ProjektQuiz\build\tests F:\Coding\ProjektQuiz\build\tests\CMakeFiles\tests_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/tests_autogen.dir/depend

