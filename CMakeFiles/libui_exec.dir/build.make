# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/gael/Documents/libui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gael/Documents/libui

# Include any dependencies generated for this target.
include CMakeFiles/libui_exec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libui_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libui_exec.dir/flags.make

CMakeFiles/libui_exec.dir/src/button/ui_button.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/button/ui_button.c.o: src/button/ui_button.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/libui_exec.dir/src/button/ui_button.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/button/ui_button.c.o   -c /home/gael/Documents/libui/src/button/ui_button.c

CMakeFiles/libui_exec.dir/src/button/ui_button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/button/ui_button.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/button/ui_button.c > CMakeFiles/libui_exec.dir/src/button/ui_button.c.i

CMakeFiles/libui_exec.dir/src/button/ui_button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/button/ui_button.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/button/ui_button.c -o CMakeFiles/libui_exec.dir/src/button/ui_button.c.s

CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.requires

CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.provides: CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.provides

CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.provides.build: CMakeFiles/libui_exec.dir/src/button/ui_button.c.o


CMakeFiles/libui_exec.dir/src/event/ui_event.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/event/ui_event.c.o: src/event/ui_event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/libui_exec.dir/src/event/ui_event.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/event/ui_event.c.o   -c /home/gael/Documents/libui/src/event/ui_event.c

CMakeFiles/libui_exec.dir/src/event/ui_event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/event/ui_event.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/event/ui_event.c > CMakeFiles/libui_exec.dir/src/event/ui_event.c.i

CMakeFiles/libui_exec.dir/src/event/ui_event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/event/ui_event.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/event/ui_event.c -o CMakeFiles/libui_exec.dir/src/event/ui_event.c.s

CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.requires

CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.provides: CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.provides

CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.provides.build: CMakeFiles/libui_exec.dir/src/event/ui_event.c.o


CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o: src/shape/ui_rect.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o   -c /home/gael/Documents/libui/src/shape/ui_rect.c

CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/shape/ui_rect.c > CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.i

CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/shape/ui_rect.c -o CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.s

CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.requires

CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.provides: CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.provides

CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.provides.build: CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o


CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o: src/texture/ui_texture.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o   -c /home/gael/Documents/libui/src/texture/ui_texture.c

CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/texture/ui_texture.c > CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.i

CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/texture/ui_texture.c -o CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.s

CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.requires

CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.provides: CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.provides

CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.provides.build: CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o


CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o: src/win/ui_display_buttons.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o   -c /home/gael/Documents/libui/src/win/ui_display_buttons.c

CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/win/ui_display_buttons.c > CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.i

CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/win/ui_display_buttons.c -o CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.s

CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.requires

CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.provides: CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.provides

CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.provides.build: CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o


CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o: src/win/ui_update_buttons.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o   -c /home/gael/Documents/libui/src/win/ui_update_buttons.c

CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/win/ui_update_buttons.c > CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.i

CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/win/ui_update_buttons.c -o CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.s

CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.requires

CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.provides: CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.provides

CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.provides.build: CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o


CMakeFiles/libui_exec.dir/src/win/ui_win.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/win/ui_win.c.o: src/win/ui_win.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/libui_exec.dir/src/win/ui_win.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/win/ui_win.c.o   -c /home/gael/Documents/libui/src/win/ui_win.c

CMakeFiles/libui_exec.dir/src/win/ui_win.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/win/ui_win.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/win/ui_win.c > CMakeFiles/libui_exec.dir/src/win/ui_win.c.i

CMakeFiles/libui_exec.dir/src/win/ui_win.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/win/ui_win.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/win/ui_win.c -o CMakeFiles/libui_exec.dir/src/win/ui_win.c.s

CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.requires

CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.provides: CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.provides

CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.provides.build: CMakeFiles/libui_exec.dir/src/win/ui_win.c.o


CMakeFiles/libui_exec.dir/src/main.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/libui_exec.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/main.c.o   -c /home/gael/Documents/libui/src/main.c

CMakeFiles/libui_exec.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/main.c > CMakeFiles/libui_exec.dir/src/main.c.i

CMakeFiles/libui_exec.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/main.c -o CMakeFiles/libui_exec.dir/src/main.c.s

CMakeFiles/libui_exec.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/main.c.o.requires

CMakeFiles/libui_exec.dir/src/main.c.o.provides: CMakeFiles/libui_exec.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/main.c.o.provides

CMakeFiles/libui_exec.dir/src/main.c.o.provides.build: CMakeFiles/libui_exec.dir/src/main.c.o


CMakeFiles/libui_exec.dir/src/ui_error.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/ui_error.c.o: src/ui_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/libui_exec.dir/src/ui_error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/ui_error.c.o   -c /home/gael/Documents/libui/src/ui_error.c

CMakeFiles/libui_exec.dir/src/ui_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/ui_error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/ui_error.c > CMakeFiles/libui_exec.dir/src/ui_error.c.i

CMakeFiles/libui_exec.dir/src/ui_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/ui_error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/ui_error.c -o CMakeFiles/libui_exec.dir/src/ui_error.c.s

CMakeFiles/libui_exec.dir/src/ui_error.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/ui_error.c.o.requires

CMakeFiles/libui_exec.dir/src/ui_error.c.o.provides: CMakeFiles/libui_exec.dir/src/ui_error.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/ui_error.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/ui_error.c.o.provides

CMakeFiles/libui_exec.dir/src/ui_error.c.o.provides.build: CMakeFiles/libui_exec.dir/src/ui_error.c.o


CMakeFiles/libui_exec.dir/src/ui_init.c.o: CMakeFiles/libui_exec.dir/flags.make
CMakeFiles/libui_exec.dir/src/ui_init.c.o: src/ui_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/libui_exec.dir/src/ui_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libui_exec.dir/src/ui_init.c.o   -c /home/gael/Documents/libui/src/ui_init.c

CMakeFiles/libui_exec.dir/src/ui_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libui_exec.dir/src/ui_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gael/Documents/libui/src/ui_init.c > CMakeFiles/libui_exec.dir/src/ui_init.c.i

CMakeFiles/libui_exec.dir/src/ui_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libui_exec.dir/src/ui_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gael/Documents/libui/src/ui_init.c -o CMakeFiles/libui_exec.dir/src/ui_init.c.s

CMakeFiles/libui_exec.dir/src/ui_init.c.o.requires:

.PHONY : CMakeFiles/libui_exec.dir/src/ui_init.c.o.requires

CMakeFiles/libui_exec.dir/src/ui_init.c.o.provides: CMakeFiles/libui_exec.dir/src/ui_init.c.o.requires
	$(MAKE) -f CMakeFiles/libui_exec.dir/build.make CMakeFiles/libui_exec.dir/src/ui_init.c.o.provides.build
.PHONY : CMakeFiles/libui_exec.dir/src/ui_init.c.o.provides

CMakeFiles/libui_exec.dir/src/ui_init.c.o.provides.build: CMakeFiles/libui_exec.dir/src/ui_init.c.o


# Object files for target libui_exec
libui_exec_OBJECTS = \
"CMakeFiles/libui_exec.dir/src/button/ui_button.c.o" \
"CMakeFiles/libui_exec.dir/src/event/ui_event.c.o" \
"CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o" \
"CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o" \
"CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o" \
"CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o" \
"CMakeFiles/libui_exec.dir/src/win/ui_win.c.o" \
"CMakeFiles/libui_exec.dir/src/main.c.o" \
"CMakeFiles/libui_exec.dir/src/ui_error.c.o" \
"CMakeFiles/libui_exec.dir/src/ui_init.c.o"

# External object files for target libui_exec
libui_exec_EXTERNAL_OBJECTS =

libui_exec: CMakeFiles/libui_exec.dir/src/button/ui_button.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/event/ui_event.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/win/ui_win.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/main.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/ui_error.c.o
libui_exec: CMakeFiles/libui_exec.dir/src/ui_init.c.o
libui_exec: CMakeFiles/libui_exec.dir/build.make
libui_exec: /usr/lib/x86_64-linux-gnu/libSDL2main.a
libui_exec: /usr/lib/x86_64-linux-gnu/libSDL2.so
libui_exec: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
libui_exec: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
libui_exec: CMakeFiles/libui_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gael/Documents/libui/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable libui_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libui_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libui_exec.dir/build: libui_exec

.PHONY : CMakeFiles/libui_exec.dir/build

CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/button/ui_button.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/event/ui_event.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/shape/ui_rect.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/texture/ui_texture.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/win/ui_display_buttons.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/win/ui_update_buttons.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/win/ui_win.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/main.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/ui_error.c.o.requires
CMakeFiles/libui_exec.dir/requires: CMakeFiles/libui_exec.dir/src/ui_init.c.o.requires

.PHONY : CMakeFiles/libui_exec.dir/requires

CMakeFiles/libui_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libui_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libui_exec.dir/clean

CMakeFiles/libui_exec.dir/depend:
	cd /home/gael/Documents/libui && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gael/Documents/libui /home/gael/Documents/libui /home/gael/Documents/libui /home/gael/Documents/libui /home/gael/Documents/libui/CMakeFiles/libui_exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libui_exec.dir/depend
