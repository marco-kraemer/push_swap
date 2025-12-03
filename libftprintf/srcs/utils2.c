/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:21:24 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 14:57:52 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*strcat_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

int	check_if_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	set_flags(t_flags *flag, const char *str, int i)
{
	while (check_if_flag(str[i]) == 1 && str[i])
	{
		if (str[i] == '-')
			flag->minus = 1;
		else if (str[i] == '0')
			flag->zero = 1;
		else if (str[i] == '#')
			flag->hashtag = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (str[i] == '+')
			flag->sign = 1;
		i++;
	}
	return (i);
}

int	set_width_precision(t_flags *flag, const char *str, int i, char *nbr)
{
	if (!ft_isdigit(str[i]) && str[i] != '.'
		&& !check_if_conversion(str[i]))
		return (-1);
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			nbr = str_append_char(nbr, str[i++]);
		flag->width = ft_atoi(nbr);
		free(nbr);
		nbr = NULL;
	}
	if (str[i] == '.')
	{
		flag->precision = 0;
		i++;
		while (ft_isdigit(str[i]))
			nbr = str_append_char(nbr, str[i++]);
		if (nbr)
		{
			flag->precision = ft_atoi(nbr);
			free(nbr);
		}
	}
	return (i);
}


// int	set_width_precision(t_flags *flag, const char *str, int i, char *nbr)
// {
// 	while (!check_if_conversion(str[i]) && str[i])
// 	{
// 		if (ft_isdigit(str[i]))
// 		{
// 			while (ft_isdigit(str[i]))
// 				nbr = str_append_char(nbr, str[i++]);
// 			flag->width = ft_atoi(nbr);
// 			free(nbr);
// 			nbr = NULL;
// 		}
// 		if (str[i] == '.')
// 		{
// 			flag->precision = 0;
// 			i++;
// 			while (ft_isdigit(str[i]))
// 				nbr = str_append_char(nbr, str[i++]);
// 			if (nbr)
// 			{
// 				flag->precision = ft_atoi(nbr);
// 				free(nbr);
// 			}
// 		}
// 		if (!ft_isdigit(str[i]) && str[i] != '.' && !check_if_conversion(str[i]))
// 			return (-1);
// 	}
// 	return (i);
// }
