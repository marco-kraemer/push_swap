/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:01:38 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 13:51:03 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_precision(char *str, int precision)
{
	int		i;
	int		j;
	int		len_str;
	char	*new;

	len_str = ft_strlen(str);
	if (len_str >= precision)
		return (str);
	new = malloc(sizeof(char) * (precision + 1));
	i = 0;
	while (i < precision - len_str)
	{
		new[i] = '0';
		i++;
	}
	j = 0;
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

int	print_hex(t_flags flag, va_list ap, char *base)
{
	unsigned int	p;
	char			*hex;
	int				lenprintf;

	p = va_arg(ap, unsigned int);
	if (p == 0)
		flag.hashtag = -1;
	hex = hex_converter(p, base);
	if (flag.precision != -1)
		flag.zero = -1;
	else if (flag.zero == 1)
		flag.precision = flag.width;
	if (flag.hashtag == 1 && flag.zero == 1)
		flag.precision = flag.precision - 2;
	hex = add_precision(hex, flag.precision);
	if (flag.hashtag == 1 && base[10] == 'a')
		hex = strcat_free(ft_strdup("0x"), hex);
	else if (flag.hashtag == 1 && base[10] == 'A')
		hex = strcat_free(ft_strdup("0X"), hex);
	lenprintf = print(hex, flag.minus, flag.width, ft_strlen(hex));
	free(hex);
	return (lenprintf);
}
