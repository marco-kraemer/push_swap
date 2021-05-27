/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/27 10:30:31 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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

void	solve(int count, t_stack *stackA, t_stack *stackB)
{
	if (count == 2)
		solve_2(stackA, count);
	else if (count == 3)
		solve_3(stackA);
	else if (count <= 5)
		solve_5(stackA, stackB, count);
	else if (count <= 100)
		solve_else(stackA, stackB, count / 5);
	else
		solve_else(stackA, stackB, count / 11);
}

int	main(int argc, char *argv[])
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc < 2)
		exit (1);
	create_stack(&stackA, argc, argv);
	if (check_order(stackA, stack_size(stackA)))
	{
		free_stack(&stackA);
		exit (1);
	}
	if (check_duplicates(stackA))
	{
		free_stack(&stackA);
		exit (0);
	}
	stackB.head = NULL;
	stackB.tail = NULL;
	solve(argc - 1, &stackA, &stackB);
	free_stack(&stackA);
	free(stackB.head);
	return (1);
}
