#ifndef PUSH_SWAP_H
# define CUB3D_H
# include <stdio.h>
# include "libft/libft.h"

typedef	struct s_node {
	int		num;
	struct	s_node *next;
	struct	s_node *prev;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	swap_a(int *stackA, int rule);
void	swap_b(int *stackB, int rule);
void	swap_a_b(int *stackA, int *stackB);

#endif
