/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:10 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 15:03:35 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libftprintf/includes/ft_printf.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

t_stack	*create_stack_a(char **nbrs);
void	stack_free(t_stack *head);

void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_a_b(t_stack **head_a, t_stack **head_b);

void	push_a(t_stack **head_a, t_stack **head_b);
void	push_b(t_stack **head_a, t_stack **head_b);

void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_a_b(t_stack **head_a, t_stack **head_b);

void	rrotate_a(t_stack **head);
void	rrotate_b(t_stack **head);
void	rrotate_a_b(t_stack **head_a, t_stack **head_b);

#endif