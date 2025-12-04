/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:31:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 12:13:33 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int nbr)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack) * 1);
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **lst, t_stack *new)
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

void	stack_free(t_stack *head)
{
	t_stack*	tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	stack_print(t_stack *head)
{
	while (head)
	{
		ft_printf("%i\n", head->nbr);
		head = head->next;
	}
}

t_stack	*get_numbers(char **nbrs)
{
	t_stack	*stack;
	int		i;
	int		j;

	i = 0;
	while (nbrs[i])
	{
		j = 0;
		while (nbrs[i][j])
		{
			if (ft_isdigit(!nbrs[i][j]))
			{
				ft_printf("Error\n");
				exit (-1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	stack = NULL;
	while (nbrs[i])
		stack_add_back(&stack, stack_new(ft_atoi(nbrs[i++])));
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	stack_a = get_numbers(argv + 1);
	stack_print(stack_a);
	stack_free(stack_a);
	return (1);
}
