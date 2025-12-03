/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:00:45 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 15:08:21 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(t_flags flag, va_list ap)
{
	char	c;
	int		i;

	c = va_arg(ap, int);
	i = 0;
	if (flag.minus == -1)
	{
		while (i < flag.width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	write (1, &c, 1);
	if (flag.minus == 1)
	{
		while (i < flag.width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + 1);
}
