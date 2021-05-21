/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/21 09:15:44 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	tmp->prev = stack->head;
	stack->head->next = tmp;
	stack->head->prev = NULL;
	write(1, "sa\n", 3);
}

void	push_a(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp;

	if (stackB->head == NULL)
		return ;
	tmp = stackB->head;
	tmp->prev = NULL;
	tmp->next = stackA->head;
	stackA->head->prev = tmp;
	write(1, "pa\n", 3);
}

void	push_a(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp;

	if (stackB->head == NULL)
		return ;
	tmp = stackB->head;
	tmp->prev = NULL;
	tmp->next = stackA->head;
	stackA->head->prev = tmp;
	write(1, "pa\n", 3);
}
