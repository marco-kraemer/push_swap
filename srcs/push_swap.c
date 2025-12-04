/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 15:45:14 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("====== Printing A and B =========\n\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			ft_printf("%i  ", stack_a->nbr);
		else
			ft_printf("   ");
		if (stack_b)
			ft_printf("%i\n", stack_b->nbr);
		else
			ft_printf(" \n");	
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	ft_printf("_   _\n\n\n");
}

// The goal is to sort the numbers in stack a in ascending order. To achieve this, you
// have the following operations at your disposal:

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

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

int	check(t_stack *stack, size_t len)
{
	int	count;

	count = 0;
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
		count++;
	}
	if (count < len)
		return (0);
	return (1);
}

int	check_stack(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
		count++;
	}
	return (1);
}

int	check_rotate(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			count++;
		stack = stack->next;
	}
	if (count < len)
		return (0);
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	t_stack	*temp;

	temp = *stack_a;
	while (!check(stack_a, len))
	{
		if ((*stack_a)->nbr > (*stack_b)->next->nbr)
			swap_a(stack_a);
		else
		{
			if (check_rotate(stack_a))
			{

			}
			push_b(stack_a, stack_b);
		}
		if (check_stack(stack_a))
		{

		}
		else
	}
}

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
	stack_print(stack_a, stack_b);
	push_swap(&stack_a, &stack_b, argc - 1);
	stack_free(stack_a);
	stack_free(stack_b);
	return (1);
}
