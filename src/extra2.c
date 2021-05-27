/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/27 10:40:27 by maraurel         ###   ########.fr       */
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

long long int	find_next_num(t_stack stackA, int *chunk, int chunk_size)
{
	int	i;

	i = 0;
	while (stackA.head)
	{
		i = 0;
		while (i < chunk_size)
		{
			if (stackA.head->num == *(chunk + i))
				return (*(chunk + i));
			i++;
		}
		stackA.head = stackA.head->next;
	}
	return (2147483648);
}
