/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:42 by maraurel          #+#    #+#             */
/*   Updated: 2021/05/18 15:58:00 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		*numbers;

	if (argc < 2)
		exit (0);
	i = 1;
	numbers  = malloc(sizeof (int) *argc);
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
		*(numbers + i - 1) = ft_atoi(argv[i]);
		printf("%i\n", *(numbers + i - 1));
		i++;
	}
	free(numbers);
	return (1);
}