NAME = e_libui

SRCS_PATH =     ./src
SRCS_PATH_1 =   win
SRCS_PATH_2 =   event
SRCS_PATH_3 =   shape
SRCS_PATH_4 =   button
SRCS_PATH_5 =   texture
SRCS_PATH_6 =   draw
SRCS_PATH_7 =   frame

#Pas le droit aux wildcards
SRCS =      $(wildcard $(SRCS_PATH)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_1)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_2)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_3)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_4)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_5)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_6)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_7)/*.c)

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


directory:
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_1) 2> /dev/null || true

clean:
		rm -rf $(OBJS_PATH)
		make clean -C $(LIBFT)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re:   		fclean all

norme:
		@norminette $(LIBFT)/*.c
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, fclean, re, directory, norme
