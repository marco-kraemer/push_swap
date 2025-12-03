/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:06:25 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 15:07:55 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_nbr_precision(char *nbr, int precision, int sign)
{
	char	*str;
	int		i;
	int		len_nbr;
	int		j;

	len_nbr = ft_strlen(nbr);
	str = malloc(sizeof(char) * (precision + 1));
	i = 0;
	j = 0;
	if (sign == 1)
	{
		str[0] = nbr[0];
		j++;
		len_nbr--;
		i++;
	}
	while (i < precision - len_nbr)
		str[i++] = '0';
	while (i < precision)
		str[i++] = nbr[j++];
	str[i] = '\0';
	free(nbr);
	return (str);
}

char	*fill_nbr_sign(char *nbr, int space)
{
	char	*str;
	int		i;

	if (ft_atoi(nbr) >= 0)
	{
		str = malloc(ft_strlen(nbr) + 2);
		if (space == -1)
			str[0] = '+';
		else
			str[0] = ' ';
		i = 0;
		while (nbr[i])
		{
			str[i + 1] = nbr[i];
			i++;
		}
		str[i + 1] = '\0';
		free(nbr);
		return (str);
	}
	return (nbr);
}
