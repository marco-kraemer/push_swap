/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <maraurel@student.42sp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/06/11 11:42:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_3(t_stack *stackA)
{
	int	c;

	if (check_order(*stackA, stack_size(*stackA)) == 1
		|| stack_size(*stackA) > 3)
		return ;
	c = compare_3(stackA->head);
	if (c == 1)
		swap_a(stackA, 0);
	if (c == 2)
	{
		swap_a(stackA, 0);
		reverse_rotate_a(stackA, 0);
	}
	if (c == 3)
		rotate_a(stackA, 0);
	if (c == 4)
	{
		swap_a(stackA, 0);
		rotate_a(stackA, 0);
	}
	if (c == 5)
		reverse_rotate_a(stackA, 0);
}

void	solve_5(t_stack *stackA, t_stack *stackB, int count)
{
	int	i;
	int	num;

	i = 0;
	while (i++ < count - 3)
		push_b(stackA, stackB, 0);
	solve_3(stackA);
	i = 0;
	while (i++ < count -3)
	{
		if (biggest_num(*stackA, *stackB))
		{
			num = get_minimun_value(*stackA);
			make_rotation(num, stackA, stackB);
		}
		else
		{
			num = find_num(stackB->head->num, *stackA);
			make_rotation(num, stackA, stackB);
		}
	}
	num = get_minimun_value(*stackA);
	solve_5_check_order(num, stackA);
}

void	solve_else2(int num, t_stack *stackA, t_stack *stackB)
{
	while (num != stackA->head->num)
	{
		if (correct_rotation(num, *stackA, stack_size(*stackA)) == 1)
			rotate_a(stackA, 0);
		else
			reverse_rotate_a(stackA, 0);
	}
	push_b(stackA, stackB, 0);
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

void	solve_else(t_stack *stackA, t_stack *stackB, int chunk_size)
{
	int				*chunk;
	static int		i;
	long long int	num;

	while (stack_size(*stackA) != 0)
	{
		chunk = get_chunk(*stackA, chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			num = find_next_num(*stackA, chunk, chunk_size);
			if (num > MAX_INT)
				break ;
			solve_else2(num, stackA, stackB);
			i++;
		}
		free (chunk);
	}
	while (stackB->head)
	{
		move_biggest_top(stackB);
		push_a(stackA, stackB, 0);
	}
}
