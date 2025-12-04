/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:46 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:14:44 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack ** head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	swap_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	swap(head);
	ft_printf("sa\n");
}   

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	swap_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	swap(head);
	ft_printf("sb\n");
}  

// ss : sa and sb at the same time.
void	swap_a_b(t_stack **head_a, t_stack **head_b)
{
	if (!*head_a || !(*head_a)->next)
		return ;
	else if (!*head_b || !(*head_b)->next)
		return ;
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}