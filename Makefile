# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 16:20:10 by msantos2          #+#    #+#              #
#    Updated: 2025/12/03 16:35:26 by msantos2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs
SRC =   $(SRC_DIR)/push_swap.c

OBJS = $(SRC:.c=.o)

HEADER = includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libftprintf
	cp libftprintf/libftprintf.a $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L. -lftprintf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libftprintf

fclean: clean
	$(MAKE) fclean -C libftprintf
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind ./$(NAME)

git: fclean
	git add .
	git commit -m "Push Swap"
	git push

.PHONY: all clean fclean re
