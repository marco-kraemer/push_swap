/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:00:54 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 14:17:00 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_pointer(t_flags flag, va_list ap)
{
	void				*p;
	char				*hex;
	int					lenprintf;
	unsigned long long	addr;

	p = va_arg(ap, void *);
	addr = (unsigned long long) p;
	if (p != 0)
	{
		hex = hex_converter(addr, "0123456789abcdef");
		hex = strcat_free(ft_strdup("0x"), hex);
	}
	else
		hex = ft_strdup("(nil)");
	lenprintf = print(hex, flag.minus, flag.width, ft_strlen(hex));
	free(hex);
	return (lenprintf);
}
