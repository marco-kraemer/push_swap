/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/19 16:26:32 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_first_node(t_stack *stackA, char *argv)
{
	t_node	*newNode;

	newNode = malloc(sizeof(t_node));
	newNode->num = ft_atoi(&argv[1]);
	newNode->next = NULL;
	stackA->head = newNode;
	stackA->tail = stackA->head;
}

void	create_stack(t_stack *stackA, int argc, char *argv[])
{
	stackA->head = malloc(sizeof(t_node));
	create_first_node(stackA, argv[1]);
}

int	main(int argc, char *argv[])
{
	t_stack	stackA;
	t_stack	stackB;

	create_stack(&stackA, argc, argv);
	stackB.head = NULL;
	stackB.tail = NULL;
	int	i = 0;
	t_node	newNode;
	newNode.next = stackA.head;
	while (i < 2)
	{
		printf("%i\n", stackA.head->num);
		newNode.next = newNode.next->next;
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
