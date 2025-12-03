/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:00:52 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 14:17:30 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_string(t_flags flag, va_list ap)
{
	char	*str;
	int		i;
	int		lenprintf;

	i = 0;
	str = va_arg(ap, char *);
	if (flag.precision == -1)
		flag.precision = ft_strlen(str);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_substr(str, 0, flag.precision);
	lenprintf = print(str, flag.minus, flag.width, flag.precision);
	free(str);
	return (lenprintf);
}
