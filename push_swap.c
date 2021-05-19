/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/19 09:03:44 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_cases(int *stackA, int *stackB,int argc)
{
	argc--;
	if (argc == 1)
		return;
	if (argc <= 3)
		return;
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
		printf("%i\n", *(stackA + i - 1));
		i++;
	}
	check_cases(stackA, stackB, argc);
	// Temporário
	printf("StackA Final:\n");
	i = 0;
	while (i < argc - 1)
	{
		printf("%i\n", *(stackA + i));
		i++;
	}
	free(stackA);
	free(stackB);
	return (1);
}
