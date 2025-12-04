/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:43 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:12:09 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rrotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	first = *head;
	last = first;
	while (last->next)
	{
		new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	last->next = first;
	*head = last;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rrotate_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rrotate(head);
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrotate_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rrotate(head);
	ft_printf("rrb\n");
}

// rrr : rra and rrb at the same time.
void	rrotate_a_b(t_stack **head_a, t_stack **head_b)
{
	if (!*head_a || !(*head_a)->next)
		return ;
	else if (!*head_b || !(*head_b)->next)
		return ;
	rrotate(head_a);
	rrotate(head_b);
	ft_printf("rrr\n");
}