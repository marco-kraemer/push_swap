/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/25 11:56:58 by maraurel         ###   ########.fr       */
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

int	find_next_num(t_stack stackA, int *chunk, int chunk_size)
{
	int	i;
	i = 0;

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
	return (8657125);
}

void	move_biggest_top(t_stack *stack)
{
	int	num;
	t_stack tmp;

	tmp = *stack;
	num = tmp.head->num;
	while (tmp.head)
	{
		if (tmp.head->num > num)
			num = tmp.head->num;
		tmp.head = tmp.head->next;
	}
	while(stack->head->num != num)
		reverse_rotate_b(stack, 0);
}

void	correct_location(int num, t_stack *stack)
{
	t_stack	tmp;

	tmp = *stack;
	if (stack->head == NULL || stack_size(*stack) <= 2)
		return ;
	if (smaller(num, *stack) || bigger(num, *stack))
	{
		while (1)
		{
			if (check_order(*stack, stack_size(*stack)))
				break ;
			rotate_b(stack, 0);
		}
	}
	else
	{
		while (1)
		{
			if (num < stack->head->num && num > stack->tail->num)
				break ;
				rotate_b(stack, 0);
		}
	}
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
	old_num = 0;
	while (i <= chunk_size)
	{
		tmp = stack;
		num = 2147483647;
		while (tmp.head)
		{
			if (tmp.head->num < num && tmp.head->num > old_num)
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

int	correct_rotation(int num, t_stack stackB, int stack_size)
{
	int	ret;
	int	dist_start;
	int	dist_end;
	t_stack	tmp;

	tmp = stackB;
	ret = -2147483648;
	while (tmp.head)
	{
		if (tmp.head->num < num && tmp.head->num > ret)
			ret = tmp.head->num;
		tmp.head = tmp.head->next;
	}
	dist_start = 0;
	while (stackB.head)
	{
		dist_start++;
		if (stackB.head->num == num)
			break ;
		stackB.head = stackB.head->next;
	}
	dist_end = dist_start - stack_size;
	if (dist_end < 0)
		dist_end = dist_end * (-1);
	printf("%i e %i\n", dist_end, dist_start);
	if (dist_start > dist_end)
		return (1);
	return (0);
}

void	solve_100(t_stack *stackA, t_stack *stackB, int count)
{
	int		chunk_size;
	int		*chunk;
	int		num;
	static int	i;

	chunk_size = count / 2;
	i = 0;
	while (stack_size(*stackA) != 0)
	{
		chunk = get_chunk(*stackA, chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			num = find_next_num(*stackA, chunk, chunk_size);
			if (num == 8657125)
				break ;
			while (num != stackA->head->num)
			{
				if (correct_rotation(num, *stackB, stack_size(*stackA)) == 1)
					rotate_a(stackA, 0);
				else
					reverse_rotate_a(stackA, 0);
			}
			push_b(stackA, stackB, 0);
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

void	solve(int count, t_stack *stackA, t_stack *stackB)
{
	if (count == 2)
		solve_2(stackA, count);
	else if (count == 3)
		solve_3(stackA);
	else if (count <= 5)
		solve_5(stackA, stackB, count);
	else
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
	//return (1);
	int	i = 0;
	printf("\nFINAL FORMATION:\n");
	while (stackA.head)
	{
		printf("%i\n", stackA.head->num);
		stackA.head = stackA.head->next;
		i++;
	}
}
