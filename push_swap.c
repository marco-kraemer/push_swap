/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/21 09:15:22 by maraurel         ###   ########.fr       */
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

void	solve_3_less(t_stack *stackA, t_stack *stackB, int count)
{
	if (count == 2)
	{
		if (check_order(*stackA, count))
			return ;
		push_b(stackA, stackB);
		return;
	}
	if (stackB->head && count == 121231)
		printf("an");
}

void	solve(int count, t_stack *stackA, t_stack *stackB)
{
	if (count <= 3)
	{
		solve_3_less(stackA, stackB, count);
	}
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
