/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <maraurel@student.42sp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/06/11 11:54:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicates(t_stack stack)
{
	int		i;
	t_stack	tmp;

	i = 0;
	tmp = stack;
	while (tmp.head)
	{
		stack.head = tmp.head;
		i = stack.head->num;
		while (stack.head->next)
		{
			stack.head = stack.head->next;
			if (stack.head->num == i)
			{
				write(1, "Error\n", 6);
				return (1);
			}	
		}
		tmp.head = tmp.head->next;
	}
	return (0);
}

void	free_stack(t_stack *stackA)
{
	while (stackA->head)
	{
		free(stackA->head);
		stackA->head = stackA->head->next;
	}
}
