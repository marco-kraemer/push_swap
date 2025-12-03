/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:42:15 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 14:47:15 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_parameter(va_list ap, const char *str, int i, int *lenprintf)
{
	t_flags	flag;

	flag = set_flags_default();
	i = set_flags(&flag, str, i);
	i = set_width_precision(&flag, str, i, NULL);
	if (i == -1)
		return (-1);
	else if (str[i] == 'c')
		*lenprintf += print_char(flag, ap);
	else if (str[i] == 's')
		*lenprintf += print_string(flag, ap);
	else if (str[i] == 'd' || str[i] == 'i')
		*lenprintf += print_int(flag, ap);
	else if (str[i] == 'p')
		*lenprintf += print_pointer(flag, ap);
	else if (str[i] == 'u')
		*lenprintf += print_uint(flag, ap);
	else if (str[i] == 'X')
		*lenprintf += print_hex(flag, ap, "0123456789ABCDEF");
	else if (str[i] == 'x')
		*lenprintf += print_hex(flag, ap, "0123456789abcdef");
	else if (str[i] == '%')
		*lenprintf += print_percent();
	return (i);
}

int	print(char *str, int minus, int nb1, int nb2)
{
	int	i;

	i = 0;
	if (minus == -1)
	{
		while (i < nb1 - nb2)
		{
			write(1, " ", 1);
			i++;
		}
	}
	ft_putstr_fd(str, 1);
	if (minus == 1)
	{
		while (i < nb1 - nb2)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + ft_strlen(str));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		lenprintf;

	lenprintf = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = check_parameter(ap, str, i + 1, &lenprintf);
			if (i == -1)
				return (-1);
		}
		else
		{
			write(1, &str[i], 1);
			lenprintf++;
		}
		i++;
	}
	va_end(ap);
	return (lenprintf);
}
