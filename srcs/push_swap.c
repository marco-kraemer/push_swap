/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 13:25:13 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int nbr)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack) * 1);
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	stack_free(t_stack *head)
{
	t_stack*	tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	stack_print(t_stack *head)
{
	while (head)
	{
		ft_printf("%i\n", head->nbr);
		head = head->next;
	}
}

t_stack	*create_stack_a(char **nbrs)
{
	t_stack	*stack;
	int		i;
	int		j;

	i = 0;
	while (nbrs[i])
	{
		j = 0;
		while (nbrs[i][j])
		{
			if (!ft_isdigit(nbrs[i][j]))
			{
				ft_printf("Error\n");
				exit (-1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	stack = NULL;
	while (nbrs[i])
		stack_add_back(&stack, stack_new(ft_atoi(nbrs[i++])));
	return (stack);
}

int	stack_size(t_stack *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

void	swap(t_stack ** head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void swap_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	swap(head);
	ft_printf("sa\n");
}   


// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void swap_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	swap(head);
	ft_printf("sb\n");
}  

// ss : sa and sb at the same time.
void swap_a_b(t_stack **head_a, t_stack **head_b)
{
	if (!*head_a || !(*head_a)->next)
		return ;
	else if (!*head_b || !(*head_b)->next)
		return ;
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!*head_a)
		return ;
	first_a = *head_a;
	first_b = *head_b;
	*head_a = first_a->next;
	first_a->next = first_b;
	*head_b = first_a;
	ft_printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	stack_a = create_stack_a(argv + 1);
	stack_b = NULL;
	// swap_a(&stack_a);
	// stack_print(stack_a);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (1);
}
