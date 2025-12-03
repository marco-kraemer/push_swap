/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 17:08:54 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*get_numbers(char **argv)
{
	t_list	*stack;
	int		i;
	int		j;
	int		nbr;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(!argv[i][j]))
			{
				ft_printf("Error\n");
				exit (-1);
			}
		}
	}
	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		ft_lstadd_back(&stack, ft_lstnew(&nbr));
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	stack_a = get_numbers(argv);
	i = 0;
	while (stack_a)
	{
		ft_printf("%i\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (1);
}
