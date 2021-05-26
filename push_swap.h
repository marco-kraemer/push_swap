#ifndef PUSH_SWAP_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>

typedef	struct s_node {
	int		num;
	struct	s_node *next;
	struct	s_node *prev;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	create_stack(t_stack *stackA, int argc, char *argv[]);

void	swap_a(t_stack *stack, int rule);
void	swap_b(t_stack *stack, int rule);
void	swap_ab(t_stack *stackA, t_stack *stackB);
void	push_a(t_stack *stackA, t_stack *stackB, int rule);
void	push_b(t_stack *stackA, t_stack *stackB, int rule);
void	rotate_a(t_stack *stack, int rule);
void	rotate_b(t_stack *stack, int rule);
void	rotate_ab(t_stack *stackA, t_stack *stackB);
void	reverse_rotate_a(t_stack *stack, int rule);
void	reverse_rotate_b(t_stack *stack, int rule);
void	reverse_rotate_ab(t_stack *stackA, t_stack *stackB);

void	solve_2(t_stack *stackA, int count);
int	compare_3(t_node *node);
void	solve_3(t_stack *stackA);
int	biggest_num(t_stack stackA, t_stack stackB);
void	solve_5(t_stack *stackA, t_stack *stackB, int count);
int	check_order(t_stack stackA, int count);

int		ft_atoi(const char *nptr);

#endif
