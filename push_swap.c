/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/20 10:36:06 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_first_node(t_stack *stackA, char *argv)
{
	t_node	*newNode;

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

	stackA->head = malloc(sizeof(t_node));
	old = create_first_node(stackA, argv[1]);
	i = 2;
	while (i < argc) 
	{
		new = create_nodes(argv[i]);
		add_node_end(stackA, old, new);
		old = new;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stackA;
	t_stack	stackB;

	create_stack(&stackA, argc, argv);
	stackB.head = NULL;
	stackB.tail = NULL;
	int	i = 0;
	while (stackA.head->next != stackA.tail + 1)
	{
		printf("%i\n", stackA.head->num);
		stackA.head = stackA.head->next;
		i++;
	}
}

/*

void	case_3num(int *stackA, int *stackB)
{
	return ;
}


void	check_cases(int *stackA, int *stackB,int argc)
{
	argc--;
	if (argc == 1)
		return;
	if (argc <= 3)
		case_3num(stackA, stackB);
	if (argc <= 5)
		return;
	if (argc <= 100)
		return;
	else
		return;
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		*stackA;
	int		*stackB;

	if (argc < 2)
		exit (0);
	i = 1;
	stackA = malloc(sizeof (int) * argc);
	stackB = malloc(sizeof (int) * argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("Fix numbers\n");
				exit (0);
			}
			j++;
		}
		*(stackA + i - 1) = ft_atoi(argv[i]);
//		printf("%i\n", *(stackA + i - 1));
		i++;
	}
	check_cases(stackA, stackB, argc);
	// Temporário
	printf("\n\nStackA Final:\n");
	i = 0;
	while (i < argc - 1)
	{
		printf("%u\n", *(stackA + i));
		i++;
	}
	free(stackA);
	free(stackB);
	return (1);
}
*/
