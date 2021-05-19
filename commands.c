/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:57 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/19 09:31:08 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stackA, int rule)
{
	int	first;
	int	second;

	first = *(stackA + 0);
	second = *(stackA + 1);
	*(stackA + 0) = second;
	*(stackA + 1) = first;
	if (rule == 0)
		write(1, "sa\n", 3);
}

void	swap_b(int *stackB, int rule)
{
	int	first;
	int	second;

	first = *(stackB + 0);
	second = *(stackB + 1);
	*(stackB + 0) = second;
	*(stackB + 1) = first;
	if (rule == 0)
		write(1, "sb\n", 3);
}

void	swap_a_b(int *stackA, int *stackB)
{
	swap_a(stackA, 1);
	swap_b(stackB, 1);
	write(1, "ss\n", 3);
}

void	push_a(int *stackA, int *stackB)
{
	if (*(stackB + 0) != 0)
	{
		return ;	
	}
}
