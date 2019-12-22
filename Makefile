NAME = e_libui

SRCS_PATH =     ./src
SRCS_PATH_1 =   win
SRCS_PATH_2 =   event
SRCS_PATH_3 =   shape
SRCS_PATH_4 =   button
SRCS_PATH_5 =   texture
SRCS_PATH_6 =   draw
SRCS_PATH_7 =   frame
SRCS_PATH_8 =   load_ui

#Pas le droit aux wildcards
SRCS =      $(wildcard $(SRCS_PATH)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_1)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_2)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_3)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_4)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_5)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_6)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_7)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_8)/*.c)

OBJS_PATH = ./objs
OBJS = $(patsubst $(SRCS_PATH)/%.c , $(OBJS_PATH)/%.o , $(SRCS))

FW_PATH = ./frameworks
LIBSDL2 = -framework SDL2 -F $(FW_PATH) -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer -rpath $(FW_PATH)
LIBFT = libft
LIBRARIES = $(LIBSDL2) ./$(LIBFT)/$(LIBFT).a

INCLUDE_PATH = ./include
CC = gcc
#CFLAGS += -Wall -Wextra -Werror -g3   -I$(INCLUDE_PATH)
CFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address  -I$(INCLUDE_PATH)\
                                                        -I$(LIBFT)/includes/\
														-I./$(LIBSDLMIXER)/\
                                                        -I$(FW_PATH)/SDL2_image.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2_ttf.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2_mixer.framework/Headers/

#Enlever le flag -fsanitize=address

all:    directory $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		$(CC) $(CFLAGS) $(LIBRARIES) $(OBJS) -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_1)/%.o : $(SRCS_PATH)/$(SRCS_PATH_1)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_2)/%.o : $(SRCS_PATH)/$(SRCS_PATH_2)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_3)/%.o : $(SRCS_PATH)/$(SRCS_PATH_3)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_4)/%.o : $(SRCS_PATH)/$(SRCS_PATH_4)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_5)/%.o : $(SRCS_PATH)/$(SRCS_PATH_5)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_6)/%.o : $(SRCS_PATH)/$(SRCS_PATH_6)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_7)/%.o : $(SRCS_PATH)/$(SRCS_PATH_7)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_8)/%.o : $(SRCS_PATH)/$(SRCS_PATH_8)/%.c
		$(CC) $(CFLAGS) -c $< -o $@


directory:
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_1) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_2) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_3) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_4) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_5) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_6) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_7) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_8) 2> /dev/null || true

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gael/Documents/libui/CMakeFiles /home/gael/Documents/libui/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gael/Documents/libui/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named e_libui

# Build rule for target.
e_libui: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 e_libui
.PHONY : e_libui

# fast build rule for target.
e_libui/fast:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/build
.PHONY : e_libui/fast

src/button/ui_button.o: src/button/ui_button.c.o

.PHONY : src/button/ui_button.o

# target to build an object file
src/button/ui_button.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/button/ui_button.c.o
.PHONY : src/button/ui_button.c.o

src/button/ui_button.i: src/button/ui_button.c.i

.PHONY : src/button/ui_button.i

# target to preprocess a source file
src/button/ui_button.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/button/ui_button.c.i
.PHONY : src/button/ui_button.c.i

src/button/ui_button.s: src/button/ui_button.c.s

.PHONY : src/button/ui_button.s

# target to generate assembly for a file
src/button/ui_button.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/button/ui_button.c.s
.PHONY : src/button/ui_button.c.s

src/draw/draw.o: src/draw/draw.c.o

.PHONY : src/draw/draw.o

# target to build an object file
src/draw/draw.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw.c.o
.PHONY : src/draw/draw.c.o

src/draw/draw.i: src/draw/draw.c.i

.PHONY : src/draw/draw.i

# target to preprocess a source file
src/draw/draw.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw.c.i
.PHONY : src/draw/draw.c.i

src/draw/draw.s: src/draw/draw.c.s

.PHONY : src/draw/draw.s

# target to generate assembly for a file
src/draw/draw.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw.c.s
.PHONY : src/draw/draw.c.s

src/draw/draw_shape.o: src/draw/draw_shape.c.o

.PHONY : src/draw/draw_shape.o

# target to build an object file
src/draw/draw_shape.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw_shape.c.o
.PHONY : src/draw/draw_shape.c.o

src/draw/draw_shape.i: src/draw/draw_shape.c.i

.PHONY : src/draw/draw_shape.i

# target to preprocess a source file
src/draw/draw_shape.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw_shape.c.i
.PHONY : src/draw/draw_shape.c.i

src/draw/draw_shape.s: src/draw/draw_shape.c.s

.PHONY : src/draw/draw_shape.s

# target to generate assembly for a file
src/draw/draw_shape.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/draw/draw_shape.c.s
.PHONY : src/draw/draw_shape.c.s

src/event/ui_event.o: src/event/ui_event.c.o

.PHONY : src/event/ui_event.o

# target to build an object file
src/event/ui_event.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/event/ui_event.c.o
.PHONY : src/event/ui_event.c.o

src/event/ui_event.i: src/event/ui_event.c.i

.PHONY : src/event/ui_event.i

# target to preprocess a source file
src/event/ui_event.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/event/ui_event.c.i
.PHONY : src/event/ui_event.c.i

src/event/ui_event.s: src/event/ui_event.c.s

.PHONY : src/event/ui_event.s

# target to generate assembly for a file
src/event/ui_event.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/event/ui_event.c.s
.PHONY : src/event/ui_event.c.s

src/main.o: src/main.c.o

.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/main.c.s
.PHONY : src/main.c.s

src/shape/ui_rect.o: src/shape/ui_rect.c.o

.PHONY : src/shape/ui_rect.o

# target to build an object file
src/shape/ui_rect.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/shape/ui_rect.c.o
.PHONY : src/shape/ui_rect.c.o

src/shape/ui_rect.i: src/shape/ui_rect.c.i

.PHONY : src/shape/ui_rect.i

# target to preprocess a source file
src/shape/ui_rect.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/shape/ui_rect.c.i
.PHONY : src/shape/ui_rect.c.i

src/shape/ui_rect.s: src/shape/ui_rect.c.s

.PHONY : src/shape/ui_rect.s

# target to generate assembly for a file
src/shape/ui_rect.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/shape/ui_rect.c.s
.PHONY : src/shape/ui_rect.c.s

src/texture/ui_text.o: src/texture/ui_text.c.o

.PHONY : src/texture/ui_text.o

# target to build an object file
src/texture/ui_text.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_text.c.o
.PHONY : src/texture/ui_text.c.o

src/texture/ui_text.i: src/texture/ui_text.c.i

.PHONY : src/texture/ui_text.i

# target to preprocess a source file
src/texture/ui_text.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_text.c.i
.PHONY : src/texture/ui_text.c.i

src/texture/ui_text.s: src/texture/ui_text.c.s

.PHONY : src/texture/ui_text.s

# target to generate assembly for a file
src/texture/ui_text.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_text.c.s
.PHONY : src/texture/ui_text.c.s

src/texture/ui_texture.o: src/texture/ui_texture.c.o

.PHONY : src/texture/ui_texture.o

# target to build an object file
src/texture/ui_texture.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_texture.c.o
.PHONY : src/texture/ui_texture.c.o

src/texture/ui_texture.i: src/texture/ui_texture.c.i

.PHONY : src/texture/ui_texture.i

# target to preprocess a source file
src/texture/ui_texture.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_texture.c.i
.PHONY : src/texture/ui_texture.c.i

src/texture/ui_texture.s: src/texture/ui_texture.c.s

.PHONY : src/texture/ui_texture.s

# target to generate assembly for a file
src/texture/ui_texture.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/texture/ui_texture.c.s
.PHONY : src/texture/ui_texture.c.s

src/ui_error.o: src/ui_error.c.o

.PHONY : src/ui_error.o

# target to build an object file
src/ui_error.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_error.c.o
.PHONY : src/ui_error.c.o

src/ui_error.i: src/ui_error.c.i

.PHONY : src/ui_error.i

# target to preprocess a source file
src/ui_error.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_error.c.i
.PHONY : src/ui_error.c.i

src/ui_error.s: src/ui_error.c.s

.PHONY : src/ui_error.s

# target to generate assembly for a file
src/ui_error.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_error.c.s
.PHONY : src/ui_error.c.s

src/ui_init.o: src/ui_init.c.o

.PHONY : src/ui_init.o

# target to build an object file
src/ui_init.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_init.c.o
.PHONY : src/ui_init.c.o

src/ui_init.i: src/ui_init.c.i

.PHONY : src/ui_init.i

# target to preprocess a source file
src/ui_init.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_init.c.i
.PHONY : src/ui_init.c.i

src/ui_init.s: src/ui_init.c.s

.PHONY : src/ui_init.s

# target to generate assembly for a file
src/ui_init.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/ui_init.c.s
.PHONY : src/ui_init.c.s

src/win/ui_display_buttons.o: src/win/ui_display_buttons.c.o

.PHONY : src/win/ui_display_buttons.o

# target to build an object file
src/win/ui_display_buttons.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_display_buttons.c.o
.PHONY : src/win/ui_display_buttons.c.o

src/win/ui_display_buttons.i: src/win/ui_display_buttons.c.i

.PHONY : src/win/ui_display_buttons.i

# target to preprocess a source file
src/win/ui_display_buttons.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_display_buttons.c.i
.PHONY : src/win/ui_display_buttons.c.i

src/win/ui_display_buttons.s: src/win/ui_display_buttons.c.s

.PHONY : src/win/ui_display_buttons.s

# target to generate assembly for a file
src/win/ui_display_buttons.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_display_buttons.c.s
.PHONY : src/win/ui_display_buttons.c.s

src/win/ui_resolve_buttons_event.o: src/win/ui_resolve_buttons_event.c.o

.PHONY : src/win/ui_resolve_buttons_event.o

# target to build an object file
src/win/ui_resolve_buttons_event.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_resolve_buttons_event.c.o
.PHONY : src/win/ui_resolve_buttons_event.c.o

src/win/ui_resolve_buttons_event.i: src/win/ui_resolve_buttons_event.c.i

.PHONY : src/win/ui_resolve_buttons_event.i

# target to preprocess a source file
src/win/ui_resolve_buttons_event.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_resolve_buttons_event.c.i
.PHONY : src/win/ui_resolve_buttons_event.c.i

src/win/ui_resolve_buttons_event.s: src/win/ui_resolve_buttons_event.c.s

.PHONY : src/win/ui_resolve_buttons_event.s

# target to generate assembly for a file
src/win/ui_resolve_buttons_event.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_resolve_buttons_event.c.s
.PHONY : src/win/ui_resolve_buttons_event.c.s

src/win/ui_update_buttons.o: src/win/ui_update_buttons.c.o

.PHONY : src/win/ui_update_buttons.o

# target to build an object file
src/win/ui_update_buttons.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_update_buttons.c.o
.PHONY : src/win/ui_update_buttons.c.o

src/win/ui_update_buttons.i: src/win/ui_update_buttons.c.i

.PHONY : src/win/ui_update_buttons.i

# target to preprocess a source file
src/win/ui_update_buttons.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_update_buttons.c.i
.PHONY : src/win/ui_update_buttons.c.i

src/win/ui_update_buttons.s: src/win/ui_update_buttons.c.s

.PHONY : src/win/ui_update_buttons.s

# target to generate assembly for a file
src/win/ui_update_buttons.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_update_buttons.c.s
.PHONY : src/win/ui_update_buttons.c.s

src/win/ui_win.o: src/win/ui_win.c.o

.PHONY : src/win/ui_win.o

# target to build an object file
src/win/ui_win.c.o:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_win.c.o
.PHONY : src/win/ui_win.c.o

src/win/ui_win.i: src/win/ui_win.c.i

.PHONY : src/win/ui_win.i

# target to preprocess a source file
src/win/ui_win.c.i:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_win.c.i
.PHONY : src/win/ui_win.c.i

src/win/ui_win.s: src/win/ui_win.c.s

.PHONY : src/win/ui_win.s

# target to generate assembly for a file
src/win/ui_win.c.s:
	$(MAKE) -f CMakeFiles/e_libui.dir/build.make CMakeFiles/e_libui.dir/src/win/ui_win.c.s
.PHONY : src/win/ui_win.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... e_libui"
	@echo "... edit_cache"
	@echo "... src/button/ui_button.o"
	@echo "... src/button/ui_button.i"
	@echo "... src/button/ui_button.s"
	@echo "... src/draw/draw.o"
	@echo "... src/draw/draw.i"
	@echo "... src/draw/draw.s"
	@echo "... src/draw/draw_shape.o"
	@echo "... src/draw/draw_shape.i"
	@echo "... src/draw/draw_shape.s"
	@echo "... src/event/ui_event.o"
	@echo "... src/event/ui_event.i"
	@echo "... src/event/ui_event.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/shape/ui_rect.o"
	@echo "... src/shape/ui_rect.i"
	@echo "... src/shape/ui_rect.s"
	@echo "... src/texture/ui_text.o"
	@echo "... src/texture/ui_text.i"
	@echo "... src/texture/ui_text.s"
	@echo "... src/texture/ui_texture.o"
	@echo "... src/texture/ui_texture.i"
	@echo "... src/texture/ui_texture.s"
	@echo "... src/ui_error.o"
	@echo "... src/ui_error.i"
	@echo "... src/ui_error.s"
	@echo "... src/ui_init.o"
	@echo "... src/ui_init.i"
	@echo "... src/ui_init.s"
	@echo "... src/win/ui_display_buttons.o"
	@echo "... src/win/ui_display_buttons.i"
	@echo "... src/win/ui_display_buttons.s"
	@echo "... src/win/ui_resolve_buttons_event.o"
	@echo "... src/win/ui_resolve_buttons_event.i"
	@echo "... src/win/ui_resolve_buttons_event.s"
	@echo "... src/win/ui_update_buttons.o"
	@echo "... src/win/ui_update_buttons.i"
	@echo "... src/win/ui_update_buttons.s"
	@echo "... src/win/ui_win.o"
	@echo "... src/win/ui_win.i"
	@echo "... src/win/ui_win.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

