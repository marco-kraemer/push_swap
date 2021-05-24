/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/24 12:52:27 by maraurel         ###   ########.fr       */
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

int	smaller_num(t_stack stackA)
{
	int	num;

	num = stackA.head->next->num;
	while (stackA.head)
	{
		if (stackA.head->num < num)
			return (0);
		stackA.head = stackA.head->next;
	}
	return (1);
}

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

int	find_next_num(t_stack stackA)
{
	int	ret;

	ret = stackA.head->num;
	while (stackA.head)
	{
		if (ret > stackA.head->num)
			ret = stackA.head->num;
		stackA.head = stackA.head->next;
	}
	return (ret);
}

void	solve_100(t_stack *stackA, t_stack *stackB, int count)
{
	int		chunk;
	int		num;
	static int	count;

	chunk = count / 10;
	count = 0;

	num = find_next_num(*stackA);
	// PUT NUM ON TOP OF STACKA
	while (num != stackA->head->num)
		rotate_a(stackA, 0);
}

/*
void	solve_100(t_stack *stackA, t_stack *stackB, int count)
{
	if (check_order(*stackA, count))
		return ;
	if (stackA->head->num > stackA->head->next->num && smaller_num(*stackA) == 0)
		swap_a(stackA, 0);
	rotate_a(stackA, 0);
	solve_100(stackA, stackB, count);
}
*/

void	solve(int count, t_stack *stackA, t_stack *stackB)
{
	if (count == 2)
		solve_2(stackA, count);
	else if (count == 3)
		solve_3(stackA);
	else if (count <= 5)
		solve_5(stackA, stackB, count);
	else if (count <= 100)
		solve_100(stackA, stackB, count);
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
