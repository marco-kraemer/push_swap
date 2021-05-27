/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:19:08 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/27 10:02:32 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*create_first_node(t_stack *stackA, char *argv)
{
	t_node	*newNode;

	if (ft_atoi(&argv[0]) < MIN_INT || ft_atoi(&argv[0]) > MAX_INT)
		exit (0);
	newNode = malloc(sizeof(t_node));
	newNode->num = ft_atoi(&argv[0]);
	newNode->next = NULL;
	stackA->head = newNode;
	stackA->tail = stackA->head;
	return (newNode);
}

static t_node	*create_nodes(char *argv)
{
	t_node	*newNode;

	if (ft_atoi(&argv[0]) < MIN_INT || ft_atoi(&argv[0]) > MAX_INT)
		return (NULL);
	newNode = malloc(sizeof(t_node));
	newNode->num = ft_atoi(&argv[0]);
	newNode->next = NULL;
	return (newNode);
}

void	add_node_end(t_stack *stackA, t_node *old, t_node *new)
{
	old->next = new;
	new->next = stackA->head;
	new->prev = old;
}

void	create_stack(t_stack *stackA, int argc, char *argv[])
{
	int		i;
	t_node	*new;
	t_node	*old;

	old = create_first_node(stackA, argv[1]);
	i = 2;
	while (i < argc)
	{
		new = create_nodes(argv[i]);
		if (new == NULL)
		{
			old->next = NULL;
			free_stack(stackA);
			exit (0);
		}
		add_node_end(stackA, old, new);
		old = new;
		i++;
	}
	new->next = NULL;
	stackA->tail = new;
}
