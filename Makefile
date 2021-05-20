# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:56:28 by maraurel          #+#    #+#              #
#    Updated: 2021/05/20 11:48:00 by maraurel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	commands.c \
	linked_list.c
	

CC = clang

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

OBJS = $(SRC:.c=.o)

$(NAME): lib
	@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $(SRC)
	@$(CC) $(FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

lib:
	@$(MAKE) -C libft
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft

clean: cleanlibft
	@$(RM) $(OBJS)
	@$(RM) *.bmp

cleanlibft:
	@$(MAKE) clean -C libft

re: fclean all

run: re
	@clear
	@./$(NAME)

memory: re
	@clear
	@ valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) map.cub
git:
	git add .
	git commit -m "Update"
	git push
