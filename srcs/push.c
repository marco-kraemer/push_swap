/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:08:43 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:11:32 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!*head_b)
		return ;
	first_a = *head_a;
	first_b = *head_b;
	*head_b = first_b->next;
	first_b->next = first_a;
	*head_a = first_b;
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!*head_a)
		return ;
	first_a = *head_a;
	first_b = *head_b;
	*head_a = first_a->next;
	first_a->next = first_b;
	*head_b = first_a;
	ft_printf("pb\n");
}