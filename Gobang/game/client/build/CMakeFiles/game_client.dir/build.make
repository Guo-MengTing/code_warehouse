# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/d4y/project/project/Gobang/game/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/d4y/project/project/Gobang/game/client/build

# Include any dependencies generated for this target.
include CMakeFiles/game_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_client.dir/flags.make

CMakeFiles/game_client.dir/main.cpp.o: CMakeFiles/game_client.dir/flags.make
CMakeFiles/game_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/d4y/project/project/Gobang/game/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_client.dir/main.cpp.o"
	/opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_client.dir/main.cpp.o -c /home/d4y/project/project/Gobang/game/client/main.cpp

CMakeFiles/game_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_client.dir/main.cpp.i"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/d4y/project/project/Gobang/game/client/main.cpp > CMakeFiles/game_client.dir/main.cpp.i

CMakeFiles/game_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_client.dir/main.cpp.s"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/d4y/project/project/Gobang/game/client/main.cpp -o CMakeFiles/game_client.dir/main.cpp.s

CMakeFiles/game_client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/game_client.dir/main.cpp.o.requires

CMakeFiles/game_client.dir/main.cpp.o.provides: CMakeFiles/game_client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/game_client.dir/build.make CMakeFiles/game_client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/game_client.dir/main.cpp.o.provides

CMakeFiles/game_client.dir/main.cpp.o.provides.build: CMakeFiles/game_client.dir/main.cpp.o


# Object files for target game_client
game_client_OBJECTS = \
"CMakeFiles/game_client.dir/main.cpp.o"

# External object files for target game_client
game_client_EXTERNAL_OBJECTS =

game_client: CMakeFiles/game_client.dir/main.cpp.o
game_client: CMakeFiles/game_client.dir/build.make
game_client: /usr/lib64/libboost_system.so
game_client: CMakeFiles/game_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/d4y/project/project/Gobang/game/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_client.dir/build: game_client

.PHONY : CMakeFiles/game_client.dir/build

CMakeFiles/game_client.dir/requires: CMakeFiles/game_client.dir/main.cpp.o.requires

.PHONY : CMakeFiles/game_client.dir/requires

CMakeFiles/game_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_client.dir/clean

CMakeFiles/game_client.dir/depend:
	cd /home/d4y/project/project/Gobang/game/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/d4y/project/project/Gobang/game/client /home/d4y/project/project/Gobang/game/client /home/d4y/project/project/Gobang/game/client/build /home/d4y/project/project/Gobang/game/client/build /home/d4y/project/project/Gobang/game/client/build/CMakeFiles/game_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_client.dir/depend

