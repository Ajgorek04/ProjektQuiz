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
CMAKE_SOURCE_DIR = F:\Coding\ProjektQuiz\tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Coding\ProjektQuiz\tests\build

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

tests_autogen/timestamp: C:/Qt/6.9.0/mingw_64/bin/moc.exe
tests_autogen/timestamp: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=F:\Coding\ProjektQuiz\tests\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target tests"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen F:/Coding/ProjektQuiz/tests/build/CMakeFiles/tests_autogen.dir/AutogenInfo.json ""
	"C:\Program Files\CMake\bin\cmake.exe" -E touch F:/Coding/ProjektQuiz/tests/build/tests_autogen/timestamp

CMakeFiles/tests.dir/codegen:
.PHONY : CMakeFiles/tests.dir/codegen

CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj: tests_autogen/mocs_compilation.cpp
CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Coding\ProjektQuiz\tests\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\tests.dir\tests_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\tests.dir\tests_autogen\mocs_compilation.cpp.obj -c F:\Coding\ProjektQuiz\tests\build\tests_autogen\mocs_compilation.cpp

CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Coding\ProjektQuiz\tests\build\tests_autogen\mocs_compilation.cpp > CMakeFiles\tests.dir\tests_autogen\mocs_compilation.cpp.i

CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Coding\ProjektQuiz\tests\build\tests_autogen\mocs_compilation.cpp -o CMakeFiles\tests.dir\tests_autogen\mocs_compilation.cpp.s

CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj: F:/Coding/ProjektQuiz/src/question.cpp
CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Coding\ProjektQuiz\tests\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj -MF CMakeFiles\tests.dir\F_\Coding\ProjektQuiz\src\question.cpp.obj.d -o CMakeFiles\tests.dir\F_\Coding\ProjektQuiz\src\question.cpp.obj -c F:\Coding\ProjektQuiz\src\question.cpp

CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Coding\ProjektQuiz\src\question.cpp > CMakeFiles\tests.dir\F_\Coding\ProjektQuiz\src\question.cpp.i

CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Coding\ProjektQuiz\src\question.cpp -o CMakeFiles\tests.dir\F_\Coding\ProjektQuiz\src\question.cpp.s

CMakeFiles/tests.dir/test_question.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test_question.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/test_question.cpp.obj: F:/Coding/ProjektQuiz/tests/test_question.cpp
CMakeFiles/tests.dir/test_question.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Coding\ProjektQuiz\tests\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/test_question.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test_question.cpp.obj -MF CMakeFiles\tests.dir\test_question.cpp.obj.d -o CMakeFiles\tests.dir\test_question.cpp.obj -c F:\Coding\ProjektQuiz\tests\test_question.cpp

CMakeFiles/tests.dir/test_question.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/test_question.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Coding\ProjektQuiz\tests\test_question.cpp > CMakeFiles\tests.dir\test_question.cpp.i

CMakeFiles/tests.dir/test_question.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test_question.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Coding\ProjektQuiz\tests\test_question.cpp -o CMakeFiles\tests.dir\test_question.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj" \
"CMakeFiles/tests.dir/test_question.cpp.obj"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests.exe: CMakeFiles/tests.dir/tests_autogen/mocs_compilation.cpp.obj
tests.exe: CMakeFiles/tests.dir/F_/Coding/ProjektQuiz/src/question.cpp.obj
tests.exe: CMakeFiles/tests.dir/test_question.cpp.obj
tests.exe: CMakeFiles/tests.dir/build.make
tests.exe: C:/Qt/6.9.0/mingw_64/lib/libQt6Test.a
tests.exe: C:/Qt/6.9.0/mingw_64/lib/libQt6Core.a
tests.exe: CMakeFiles/tests.dir/linkLibs.rsp
tests.exe: CMakeFiles/tests.dir/objects1.rsp
tests.exe: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\Coding\ProjektQuiz\tests\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests.exe
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend: tests_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Coding\ProjektQuiz\tests F:\Coding\ProjektQuiz\tests F:\Coding\ProjektQuiz\tests\build F:\Coding\ProjektQuiz\tests\build F:\Coding\ProjektQuiz\tests\build\CMakeFiles\tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tests.dir/depend

