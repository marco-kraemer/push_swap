/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:30:20 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	stack_a = create_stack_a(argv + 1);
	stack_b = NULL;
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	swap_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	swap_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("\n\n ===== reverse rotate a ======\n\n");
	rrotate_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	rrotate_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("\n\n ===== push b ======\n\n");
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	ft_printf("\n\n ===== reverse rotate b ======\n\n");
	rrotate_b(&stack_b);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	rrotate_b(&stack_b);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	// push_a(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// ft_printf("Stack A:\n");
	// stack_print(stack_a);
	// ft_printf("Stack B:\n");
	// stack_print(stack_b);
	ft_printf("\n\n ===== rotate a ======\n\n");
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	rotate_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	rotate_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	rotate_a(&stack_a);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("\n\n ===== rotate b ======\n\n");
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	rotate_b(&stack_b);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	rotate_b(&stack_b);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	rotate_b(&stack_b);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	ft_printf("\n\n ===== rotate a and b ======\n\n");
	rotate_a_b(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	rotate_a_b(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	ft_printf("\n\n ===== push a ======\n\n");
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	stack_print(stack_a);
	ft_printf("Stack B:\n");
	stack_print(stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (1);
}
