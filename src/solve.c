/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/27 10:49:26 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_2(t_stack *stackA, int count)
{
	if (check_order(*stackA, count))
		return ;
	swap_a(stackA, 0);
}

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
	while (i < count - 3)
	{
		push_b(stackA, stackB, 0);
		i++;
	}
	solve_3(stackA);
	i = 0;
	while (i < count -3)
	{
		if (biggest_num(*stackA, *stackB))
		{
			num = get_minimun_value(*stackA);
			while (num != stackA->head->num)
			{
				if (correct_rotation(num, *stackA, stack_size(*stackA)))
					rotate_a(stackA, 0);
				else
					reverse_rotate_a(stackA, 0);
			}
			push_a(stackA, stackB, 0);
		}
		else
		{
			num = find_num(stackB->head->num, *stackA);
			while (num != stackA->head->num)
			{
				if (correct_rotation(num, *stackA, stack_size(*stackA)))
					rotate_a(stackA, 0);
				else
					reverse_rotate_a(stackA, 0);
			}
			push_a(stackA, stackB, 0);
		}
		i++;
	}
	num = get_minimun_value(*stackA);
	while (num != stackA->head->num)
	{
		if (correct_rotation(num, *stackA, stack_size(*stackA)))
			rotate_a(stackA, 0);
		else
			reverse_rotate_a(stackA, 0);
	}	
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
			solve_else2( num, stackA, stackB);
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
