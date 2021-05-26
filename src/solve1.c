/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:51:33 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/26 14:37:29 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_2(t_stack *stackA, int count)
{
	if (check_order(*stackA, count))
		return ;
	swap_a(stackA, 0);
}

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

	ret = 2147483647;
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
	// PEGAR NÚMERO MAIOR MAIS PROXIMO DE NUM
	int	ret;

	ret = 2147483647;
	while (stackA.head)
	{
		if (stackA.head->num > num && stackA.head->num < ret)
			ret = stackA.head->num;
		stackA.head = stackA.head->next;
	}
	return (ret);
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
			num = get_minimun_value(*stackA); // MENOR NÚMERO DE STACKA
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
			num = find_num(stackB->head->num, *stackA); // MENOR NÚMERO MAIOR QUE STACKB->HEAD->NUM (NÚMERO Q DEVE FICAR NO TOPO DE STACK A)
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
	num = get_minimun_value(*stackA); // MENOR NÚMERO DE STACKA
	while (num != stackA->head->num)
	{
		if (correct_rotation(num, *stackA, stack_size(*stackA)))
			rotate_a(stackA, 0);
		else
			reverse_rotate_a(stackA, 0);
	}	
}
