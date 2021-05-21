/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/21 12:34:20 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack stackA, int count)
{
	int	prev;
	int	next;
	int	i;

	i = 0;
	while (stackA.head->next)
	{
		prev = stackA.head->num;
		stackA.head = stackA.head->next;
		next = stackA.head->num;
		if (prev > stackA.head->num)
			return (0);
		i += 1;
	}
	if (i == count - 1)
		return (1);
	return (0);
}

void	solve_2(t_stack *stackA, int count)
{
	if (check_order(*stackA, count))
		return ;
	swap_a(stackA, 0);
}

int	compare_3(t_node *node)
{
	// TOP TO MIDDLE, TOP TO BOTTOM, MIDDLE TO BOTTOM
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

void	solve_5(t_stack *stackA, t_stack *stackB, int count)
{
	push_b(stackA, stackB, 0);
	if (count == 5)
		push_b(stackA, stackB, 0);
	solve_3(stackA);
//	printf("%i e %i\n", stackB->head->num, stackA->tail->num);
	while (stackB->head->num < stackA->tail->num)
		rotate_a(stackA, 0);
	push_a(stackA, stackB, 0);
	while (check_order(*stackA, count) == 0)
		rotate_a(stackA, 0);
	if (count == 5)
	{
		push_a(stackA, stackB, 0);
		if (check_order(*stackA, count) == 0)
			rotate_a(stackA, 0);
	}
}

void	solve(int count, t_stack *stackA, t_stack *stackB)
{
	if (count == 2)
		solve_2(stackA, count);
	else if (count == 3)
		solve_3(stackA);
	else if (count <= 5)
		solve_5(stackA, stackB, count);
}

int	main(int argc, char *argv[])
{
	t_stack	stackA;
	t_stack	stackB;

	create_stack(&stackA, argc, argv);
	stackB.head = NULL;
	stackB.tail = NULL;
	solve(argc - 1, &stackA, &stackB);
	int	i = 0;
	printf("\nFINAL FORMATION:\n");
	while (stackA.head)
	{
		printf("%i\n", stackA.head->num);
		stackA.head = stackA.head->next;
		i++;
	}
}
