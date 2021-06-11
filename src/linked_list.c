/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <maraurel@student.42sp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:19:08 by maraurel          #+#    #+#             */
/*   Updated: 2021/06/11 14:07:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	j;
	size_t	value;

	j = 1;
	i = 0;
	value = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j = j * (-1);
		i++;
	}
	while (nptr[i])
	{
		value = value * 10 + (nptr[i] - '0');
		if (nptr[i] <= 47 || nptr[i] >= 58)
			return (2147483648);
		i++;
	}
	return (value * j);
}

static t_node	*create_first_node(t_stack *stackA, char *argv)
{
	t_node	*newNode;

	if (ft_atoi(&argv[0]) < MIN_INT || ft_atoi(&argv[0]) > MAX_INT)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
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
			write(1, "Error\n", 6);
			old->next = NULL;
			free_stack(stackA, 0);
			exit (0);
		}
		add_node_end(stackA, old, new);
		old = new;
		i++;
	}
	new->next = NULL;
	stackA->tail = new;
}
