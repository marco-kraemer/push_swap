/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 17:31:48 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

t_stack	*create_stack(int nbr)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack) * 1);
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	stack_add(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_stack	*get_numbers(char **argv)
{
	t_stack	*stack;
	int		i;
	int		j;

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
			j++;
		}
		i++;
	}
	i = 1;
	stack = NULL;
	while (argv[i])
		stack_add(&stack, create_stack(ft_atoi(argv[i++])));
	return (stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	stack_a = get_numbers(argv);
	i = 0;
	while (stack_a)
	{
		ft_printf("%i\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	return (1);
}
