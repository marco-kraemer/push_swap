/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/20 12:40:57 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stackA)
{
	t_node	*tmp;

	tmp = stackA->head;
	stackA->head = stackA->head->next;
	tmp->next = stackA->head->next;
	tmp->prev = stackA->head;
	stackA->head->next = tmp;
	stackA->head->prev = NULL;
	write(1, "sa\n", 3);
}
