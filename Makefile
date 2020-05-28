# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 16:01:28 by gmonacho          #+#    #+#              #
#    Updated: 2020/05/29 00:59:20 by gal              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libui.a

CC = gcc

SRCS =	srcs/ui_error.c\
		srcs/ui_init.c\
		srcs/button/ui_button.c\
		srcs/button/ui_simple_button.c\
		srcs/button/ui_text_area.c\
		srcs/button/ui_text_entry_button.c\
		srcs/draw/draw.c\
		srcs/draw/draw_shape.c\
		srcs/event/ui_event.c\
		srcs/frame/ui_frame.c\
		srcs/frame/ui_simple_frame.c\
		srcs/load_ui/ui_check_line_name.c\
		srcs/load_ui/ui_general_get.c\
		srcs/load_ui/ui_get_b_type.c\
		srcs/load_ui/ui_get_flags.c\
		srcs/load_ui/ui_get_type.c\
		srcs/load_ui/ui_load.c\
		srcs/load_ui/ui_parse_button.c\
		srcs/load_ui/ui_parse_buttons.c\
		srcs/load_ui/ui_parse_frame.c\
		srcs/load_ui/ui_parse_frame_data.c\
		srcs/load_ui/ui_parse_simple_button.c\
		srcs/load_ui/ui_parse_simple_frame.c\
		srcs/load_ui/ui_parse_text_area.c\
		srcs/load_ui/ui_parse_text_entry_button.c\
		srcs/load_ui/ui_parse_text_entry_cut.c\
		srcs/load_ui/ui_parse_texture.c\
		srcs/load_ui/ui_parse_type.c\
		srcs/shape/ui_rect.c\
		srcs/texture/ui_draw_one_line_return.c\
		srcs/texture/ui_draw_text_line.c\
		srcs/texture/ui_draw_text_line_return.c\
		srcs/texture/ui_free_texture_set.c\
		srcs/texture/ui_get_dst_y.c\
		srcs/texture/ui_renderer.c\
		srcs/texture/ui_text.c\
		srcs/texture/ui_texture.c\
		srcs/texture/ui_texture_list.c\
		srcs/win/ui.c\
		srcs/win/ui_call_button_function.c\
		srcs/win/ui_check_text_entry_button.c\
		srcs/win/ui_display_buttons.c\
		srcs/win/ui_display_frames.c\
		srcs/win/ui_display_simple.c\
		srcs/win/ui_display_text_area.c\
		srcs/win/ui_display_text_entry.c\
		srcs/win/ui_get_button_by_id.c\
		srcs/win/ui_get_side_rect.c\
		srcs/win/ui_mouse.c\
		srcs/win/ui_resolve_buttons_event.c\
		srcs/win/ui_resolve_text_entry_button.c\
		srcs/win/ui_set_button_function.c\
		srcs/win/ui_update_buttons.c\
		srcs/win/ui_update_frames.c\
		srcs/win/ui_win.c\
		srcs/win/ui_win_size.c\
		srcs/win/ui_win_update_ui.c


HEADERS =	-I./includes\
			-I./libft/includes

OBJS = $(SRCS:.c=.o)

LDFLAGS= -lft -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "\nlibui compiled"

%.o: %.c 
	@printf "|"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@echo "objects deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) is deleted"

re: fclean all

.PHONY: clean
		fclean
		re

