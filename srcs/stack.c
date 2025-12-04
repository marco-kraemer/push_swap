/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:08:59 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/04 14:35:18 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_free(t_stack *head)
{
	t_stack	*tmp;

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

static t_stack	*stack_new(int nbr)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack) * 1);
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

static void	stack_add_back(t_stack **lst, t_stack *new)
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

t_stack	*create_stack_a(char **nbrs)
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
			if (!ft_isdigit(nbrs[i][j]))
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
