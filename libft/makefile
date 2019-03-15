# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 16:01:28 by gmonacho     #+#   ##    ##    #+#        #
#    Updated: 2019/03/15 21:22:52 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRC =	$(wildcard *.c)

HEADER = ./includes/libft.h

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra  -Werror

all: $(NAME)

%.o: %.c 
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "#"

$(NAME): $(OBJ)
		@printf "#"
		@ar rcs $(NAME) $(OBJ)
		@echo "\nlib compiled"

clean:
	@rm -rf $(OBJ)
	@echo "objects deleted"

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) is deleted"

re: fclean all
