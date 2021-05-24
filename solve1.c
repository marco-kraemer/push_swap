/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:51:33 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/24 10:52:15 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_2(t_stack *stackA, int count)
{
	if (check_order(*stackA, count))
		return ;
	swap_a(stackA, 0);
}

int	compare_3(t_node *node)
{
	if (node->num > node->next->num && node->num < node->next->next->num && node->next->num < node->next->next->num)
		return (1);
	if (node->num > node->next->num && node->num > node->next->next->num && node->next->num > node->next->next->num)
		return (2);
	if (node->num > node->next->num && node->num > node->next->next->num && node->next->num < node->next->next->num)
		return (3);
	if (node->num < node->next->num && node->num < node->next->next->num && node->next->num > node->next->next->num)
		return (4);
	if (node->num < node->next->num && node->num > node->next->next->num && node->next->num > node->next->next->num)
		return (5);
	return (0);
}

void	solve_3(t_stack *stackA)
{
	int	c;

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

int	biggest_num(t_stack stackA, t_stack stackB)
{
	int	num;

	num = stackB.head->num;
	while(stackA.head)
	{
		if (stackA.head->num > num)
			return (0);
		stackA.head = stackA.head->next;
	}
	return (1);
}

void	solve_5(t_stack *stackA, t_stack *stackB, int count)
{
	static int	i;
	static int	j;

	while (i < count - 3)
	{
		push_b(stackA, stackB, 0);
		i++;
	}
	solve_3(stackA);
	while (1)
	{
		if (stackB->head->num < stackA->head->num
			|| biggest_num(*stackA, *stackB) == 1)
		{
			push_a(stackA, stackB, 0);
			break ;
		}
		rotate_a(stackA, 0);
	}
	if (count == 5 && j == 0)
	{
		j++;
		while (check_order(*stackA, count - 1) == 0)
			rotate_a(stackA, 0);
		solve_5(stackA, stackB, count);
	}
	while (check_order(*stackA, count) == 0)
		rotate_a(stackA, 0);
}
