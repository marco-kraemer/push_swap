/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <maraurel@student.42sp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:20:49 by maraurel          #+#    #+#             */
/*   Updated: 2021/06/15 11:58:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_2(t_stack *stackA, int count)
{
	if (check_order(*stackA, count))
		return ;
	swap_a(stackA, 0);
}

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

void	one_num(char *argv[])
{
	int	i;

	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i] < '0' || argv[0][i] > '9')
		{
			write(1, "Error\n", 6);
			break ;
		}
		i++;
	}
	free(argv[0]);
	free(argv);
	exit (1);
}

int	main(int argc, char *argv[])
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc <= 1)
		exit (EXIT_SUCCESS);
	create_stack(&stackA, argc, argv);
	if (check_duplicates(stackA) || check_order(stackA, stack_size(stackA)))
		free_stack(&stackA, 1);
	stackB.head = NULL;
	stackB.tail = NULL;
	solve(argc - 1, &stackA, &stackB);
	free_stack(&stackA, 0);
	free(stackB.head);
}
