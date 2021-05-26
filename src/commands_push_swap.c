/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/26 14:26:11 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack, int rule)
{
	int	n;

	if (!(stack->head) || !(stack->head->next))
		return ;
	n = stack->head->num;
	stack->head->num = stack->head->next->num;
	stack->head->next->num = n;
	if (rule == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack, int rule)
{
	int	n;

	if (!(stack->head) || !(stack->head->next))
		return ;
	n = stack->head->num;
	stack->head->num = stack->head->next->num;
	stack->head->next->num = n;
	if (rule == 0)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stack *stackA, t_stack *stackB)
{
	swap_a(stackA, 1);
	swap_b(stackB, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *stackA, t_stack *stackB, int rule)
{
	t_node	*tmp;

	if (stackB->head == NULL)
		return ;
	tmp = stackB->head;
	stackB->head = stackB->head->next;
	tmp->prev = NULL;
	if (stackA->head)
		stackA->head->prev = tmp;
	else
		stackA->tail = tmp;
	tmp->next = stackA->head;
	stackA->head = tmp;
	stackA->head->prev = NULL;
	if (rule == 0)
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stackA, t_stack *stackB, int rule)
{
	t_node	*tmp;

	if (stackA->head == NULL)
		return ;
	tmp = stackA->head;
	stackA->head = stackA->head->next;
	tmp->prev = NULL;
	if (stackB->head)
		stackB->head->prev = tmp;
	else
		stackB->tail = tmp;
	tmp->next = stackB->head;
	stackB->head = tmp;
	stackB->head->prev = NULL;
	if (rule == 0)
		write(1, "pb\n", 3);
}
