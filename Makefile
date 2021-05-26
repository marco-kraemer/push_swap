# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:56:28 by maraurel          #+#    #+#              #
#    Updated: 2021/05/26 09:01:27 by maraurel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	commands.c \
	linked_list.c \
	solve1.c \
	ft_atoi.c
	

CC = clang

FLAGS = -Wall -Wextra -Werror

all:
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

OBJS = $(SRC:.c=.o)

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS)

re: fclean all

git:
	git add .
	git commit -m "Update"
	git push
