/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/24 15:53:46 by maraurel         ###   ########.fr       */
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

int	find_next_num(t_stack stackA, int *chunk, int chunk_size)
{
	int	i;

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
	return (333);
}

int	*get_chunk(t_stack stack, int chunk_size)
{
	int	*chunk;
	int	num;
	int	old_num;
	int	i;
	t_stack	tmp;

	tmp = stack;
	i = 0;
	chunk = malloc(10 * sizeof(int));
	num = stack.head->num;
	old_num = 0;
	while (i <= chunk_size)
	{
		tmp = stack;
		num = stack.head->num;
		while (tmp.head->next)
		{
			if (num > tmp.head->num && tmp.head->num > old_num)
			{
				num = tmp.head->num;
			}
			tmp.head = tmp.head->next;
		}
		old_num = num;
		*(chunk + i) = num;
		i++;
	}
	return (chunk);
}

int	bigger(int num, t_stack stackB)
{
	if (stackB.head == NULL)
		return (0);
	while (stackB.head)
	{
		if (stackB.head->num > num)
			return (0);
		stackB.head = stackB.head->next;
	}
	return (1);
}

int	smaller(int num, t_stack stackB)
{
	if (stackB.head == NULL)
		return (0);
	while (stackB.head)
	{
		if (stackB.head->num < num)
			return (0);
		stackB.head = stackB.head->next;
	}
	return (1);
}

void	correct_location(int num, t_stack *stackB)
{
	t_stack	tmp;

	tmp = *stackB;
	if (stackB->head == NULL || stack_size(*stackB) <= 2)
		return ;
	if (smaller(num, *stackB) || bigger(num, *stackB))
	{
		while (1)
		{
			if (check_order(*stackB, stack_size(*stackB)))
				break ;
			rotate_b(stackB, 0);
		}
	}
	else
	{
		while (1)
		{
			if (num < stackB->head->num && num > stackB->tail->num)
				break ;
			rotate_b(stackB, 0);
		}
	}
}

void	solve_100(t_stack *stackA, t_stack *stackB, int count)
{
	int		chunk_size;
	int		*chunk;
	int		num;
	static int	i;

	chunk_size = count / 10;
	i = 0;
	while (stack_size(*stackA) != 0)
	{
		chunk = get_chunk(*stackA, chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			num = find_next_num(*stackA, chunk, chunk_size);
			// PUT NUM ON TOP OF STACKA
			while (num != stackA->head->num)
			{
				printf("%i\n", num);
				rotate_a(stackA, 0);
			}
			correct_location(num, stackB);
			push_b(stackA, stackB, 0);
			i++;
		}
		free (chunk);
	}
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
	while (stackB.head)
	{
		printf("%i\n", stackB.head->num);
		stackB.head = stackB.head->next;
		i++;
	}
}
