/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:26 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 14:17:43 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_uint(t_flags flag, va_list ap)
{
	char			*nbr;
	unsigned int	n;
	int				lenprintf;

	n = va_arg(ap, unsigned int);
	if (n == 0 && flag.precision == 0)
		nbr = ft_strdup("");
	else
	{
		if (flag.precision != -1)
			flag.zero = -1;
		else if (flag.zero == 1)
			flag.precision = flag.width;
		nbr = ft_itoa(n);
		nbr = add_precision(nbr, flag.precision);
	}
	lenprintf = print(nbr, flag.minus, flag.width, ft_strlen(nbr));
	free(nbr);
	return (lenprintf);
}
