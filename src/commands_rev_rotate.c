/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/26 14:27:41 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack *stack, int rule)
{
	if (stack->head == NULL || stack->tail == NULL)
		return ;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail =stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev = NULL;
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
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack *stackA, t_stack *stackB)
{
	reverse_rotate_a(stackA, 1);
	reverse_rotate_b(stackB, 1);
	write(1, "rrr\n", 4);
}
