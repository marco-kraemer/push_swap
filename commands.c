/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/21 10:30:04 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack, int rule)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	tmp->prev = stack->head;
	stack->head->next = tmp;
	stack->head->prev = NULL;
	if (rule == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack, int rule)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	tmp->prev = stack->head;
	stack->head->next = tmp;
	stack->head->prev = NULL;
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

void	rotate_a(t_stack *stack, int rule)
{
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail = stack->tail->next;
	stack->tail->next = NULL;;
	if (rule == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack, int rule)
{
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail = stack->tail->next;
	stack->tail->next = NULL;
	if (rule == 0)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_stack *stackA, t_stack *stackB)
{
	rotate_a(stackA, 1);
	rotate_b(stackB, 1);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack, int rule)
{
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->tail = stack->tail->prev;
	stack->head = stack->head->prev;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
	if (rule == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack, int rule)
{
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->tail = stack->tail->prev;
	stack->head = stack->head->prev;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
	if (rule == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_ab(t_stack *stackA, t_stack *stackB)
{
	reverse_rotate_a(stackA, 1);
	reverse_rotate_b(stackB, 1);
	write(1, "rrr\n", 4);
}
