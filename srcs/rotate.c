/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:38 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:11:48 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	*head = first->next;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rotate(head);
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rotate(head);
	ft_printf("rb\n");
}
// rr : ra and rb at the same time.
void	rotate_a_b(t_stack **head_a, t_stack **head_b)
{
	if (!*head_a || !(*head_a)->next)
		return ;
	if (!*head_b || !(*head_b)->next)
		return ;
	rotate(head_a);
	rotate(head_b);
	ft_printf("rr\n");
}