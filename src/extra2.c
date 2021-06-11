/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <maraurel@student.42sp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/06/11 11:42:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.head)
	{
		stack.head = stack.head->next;
		i++;
	}
	return (i);
}

int	*get_chunk(t_stack stack, int chunk_size)
{
	int				*chunk;
	int				num;
	int				i;
	long long int	old_num;
	t_stack			tmp;

	tmp = stack;
	i = 0;
	chunk = malloc(10 * sizeof(int));
	old_num = MIN_INT - 1;
	while (i <= chunk_size)
	{
		tmp = stack;
		num = MAX_INT;
		while (tmp.head)
		{
			if (tmp.head->num < num && tmp.head->num > old_num)
				num = tmp.head->num;
			tmp.head = tmp.head->next;
		}
		old_num = num;
		*(chunk + i) = num;
		i++;
	}
	return (chunk);
}

int	correct_rotation(int num, t_stack stackB, int stack_size)
{
	int	dist_start;
	int	dist_end;

	dist_start = 0;
	while (stackB.head)
	{
		if (stackB.head->num == num)
			break ;
		dist_start++;
		stackB.head = stackB.head->next;
	}
	dist_end = dist_start - stack_size;
	if (dist_end < 0)
		dist_end = dist_end * (-1);
	if (dist_start < dist_end)
		return (1);
	return (0);
}

void	move_biggest_top(t_stack *stack)
{
	int		num;
	t_stack	tmp;

	tmp = *stack;
	num = tmp.head->num;
	while (tmp.head)
	{
		if (tmp.head->num > num)
			num = tmp.head->num;
		tmp.head = tmp.head->next;
	}
	while (stack->head->num != num)
	{
		if (correct_rotation(num, *stack, stack_size(*stack)) == 1)
			rotate_b(stack, 0);
		else
			reverse_rotate_b(stack, 0);
	}
}

void	solve_5_check_order(int num, t_stack *stackA)
{
	while (num != stackA->head->num)
	{
		if (correct_rotation(num, *stackA, stack_size(*stackA)))
			rotate_a(stackA, 0);
		else
			reverse_rotate_a(stackA, 0);
	}	
}
