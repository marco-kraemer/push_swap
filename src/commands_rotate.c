/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/26 14:27:27 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
