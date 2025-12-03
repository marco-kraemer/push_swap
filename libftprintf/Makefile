# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 12:54:25 by msantos2          #+#    #+#              #
#    Updated: 2025/12/02 15:07:21 by msantos2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs
SRC =   $(SRC_DIR)/ft_printf.c \
        $(SRC_DIR)/print_char.c \
        $(SRC_DIR)/print_hex.c \
        $(SRC_DIR)/print_int.c \
		$(SRC_DIR)/print_int2.c \
        $(SRC_DIR)/print_percent.c \
        $(SRC_DIR)/print_pointer.c \
        $(SRC_DIR)/print_str.c \
        $(SRC_DIR)/print_uint.c \
        $(SRC_DIR)/utils.c \
		$(SRC_DIR)/utils2.c

OBJS = $(SRC:.c=.o)

HEADER = includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

compile_lib:
	$(CC) $(CFLAGS) srcs/main.c -L. -lftprintf

run: all compile_lib
	./a.out
	rm a.out

valgrind: all compile_lib
	valgrind ./a.out
	rm a.out

git: fclean
	git add .
	git commit -m "Printf"
	git push

.PHONY: all clean fclean re
