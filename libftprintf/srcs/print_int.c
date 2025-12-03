/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:00:48 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 17:10:25 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_conditions(t_flags *flag, char *nbr)
{
	int	check;

	check = 1;
	if (flag->precision == -1 || flag->precision < (int)ft_strlen(nbr))
		check = -1;
	if (flag->precision != -1)
		flag->zero = -1;
	else
		flag->precision = ft_strlen(nbr);
	if (flag->precision < (int)ft_strlen(nbr) && ft_atoi(nbr) != 0)
		flag->precision = ft_strlen(nbr);
	if (flag->zero == 1)
		flag->minus = -1;
	if (ft_atoi(nbr) < 0)
		flag->sign = 1;
	if (flag->sign == 1)
		flag->space = -1;
	if (flag->sign == 1 || flag->space == 1)
	{
		nbr = fill_nbr_sign(nbr, flag->space);
		if (nbr[0] == '+' || nbr[0] == ' ' || (nbr[0] == '-' && check == 1)
			|| flag->precision > (int)ft_strlen(nbr))
			flag->precision++;
	}
	return (nbr);
}

static int	zero_false(char *nbr, t_flags flag)
{
	int	i;
	int	lenprintf;

	i = 0;
	lenprintf = 0;
	if (flag.minus == -1)
	{
		while (i < flag.width - flag.precision)
		{
			write(1, " ", 1);
			lenprintf++;
			i++;
		}
	}
	ft_putstr_fd(nbr, 1);
	if (flag.minus == 1)
	{
		while (i < flag.width - flag.precision)
		{
			write(1, " ", 1);
			lenprintf++;
			i++;
		}
	}
	return (lenprintf + ft_strlen(nbr));
}

static int	zero_true(char *nbr, t_flags flag, int i)
{
	int	lenprintf;

	lenprintf = 0;
	flag.precision = ft_strlen(nbr);
	if (flag.sign == 1)
	{
		write(1, &nbr[i], 1);
		lenprintf++;
	}
	while (i < flag.width - flag.precision)
	{
		write(1, "0", 1);
		lenprintf++;
		i++;
	}
	i = 0;
	if (flag.sign == 1)
		i = 1;
	while (nbr[i])
	{
		write(1, &nbr[i++], 1);
		lenprintf++;
	}
	return (lenprintf);
}

int	print_int(t_flags flag, va_list ap)
{
	char	*nbr;
	int		lenprintf;

	nbr = ft_itoa(va_arg(ap, int));
	nbr = int_conditions(&flag, nbr);
	lenprintf = 0;
	if (flag.zero == -1)
	{
		nbr = fill_nbr_precision(nbr, flag.precision, flag.sign);
		lenprintf = zero_false(nbr, flag);
	}
	else
		lenprintf = zero_true(nbr, flag, 0);
	free(nbr); 
	return (lenprintf);
}
