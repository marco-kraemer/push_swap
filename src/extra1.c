/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/27 11:06:21 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_3(t_node *node)
{
	if (node->num > node->next->num && node->num < node->next->next->num
		&& node->next->num < node->next->next->num)
		return (1);
	if (node->num > node->next->num && node->num > node->next->next->num
		&& node->next->num > node->next->next->num)
		return (2);
	if (node->num > node->next->num && node->num > node->next->next->num
		&& node->next->num < node->next->next->num)
		return (3);
	if (node->num < node->next->num && node->num < node->next->next->num
		&& node->next->num > node->next->next->num)
		return (4);
	if (node->num < node->next->num && node->num > node->next->next->num
		&& node->next->num > node->next->next->num)
		return (5);
	return (0);
}

int	biggest_num(t_stack stackA, t_stack stackB)
{
	int	num;

	num = stackB.head->num;
	while (stackA.head)
	{
		if (stackA.head->num > num)
			return (0);
		stackA.head = stackA.head->next;
	}
	return (1);
}

int	get_minimun_value(t_stack stackA)
{
	int	ret;

	ret = MAX_INT;
	while (stackA.head)
	{
		if (stackA.head->num < ret)
			ret = stackA.head->num;
		stackA.head =stackA.head->next;
	}
	return (ret);
}

int	find_num(int num, t_stack stackA)
{
	int	ret;

	ret = MAX_INT;
	while (stackA.head)
	{
		if (stackA.head->num > num && stackA.head->num < ret)
			ret = stackA.head->num;
		stackA.head = stackA.head->next;
	}
	return (ret);
}

void	make_rotation(int num, t_stack *stackA, t_stack *stackB)
{
	while (num != stackA->head->num)
	{
		if (correct_rotation(num, *stackA, stack_size(*stackA)))
			rotate_a(stackA, 0);
		else
			reverse_rotate_a(stackA, 0);
	}
	push_a(stackA, stackB, 0);
}
