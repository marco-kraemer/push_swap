/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:58 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 14:59:33 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_if_flag(const char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

char	*str_append_char(char *dest, const char c)
{
	size_t	i;
	size_t	dest_len;
	char	*temp;

	if (dest == NULL)
	{
		dest = malloc(sizeof(char) + 2);
		dest[0] = c;
		dest[1] = '\0';
		return (dest);
	}
	i = 0;
	temp = ft_strdup(dest);
	dest_len = ft_strlen(dest);
	free(dest);
	dest = malloc(sizeof(char) * (dest_len + 2));
	while (temp[i])
	{
		dest[i] = temp[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(temp);
	return (dest);
}

char	*reverse_str(char *str)
{
	char	*rev;
	int		len_str;
	int		i;

	len_str = ft_strlen(str);
	rev = malloc(sizeof(char) + len_str + 1);
	i = 0;
	while (len_str > 0)
	{
		rev[i] = str[len_str - 1];
		i++;
		len_str--;
	}
	rev[i] = '\0';
	free(str);
	return (rev);
}

char	*hex_converter(unsigned long long nbr, char *base)
{
	int		remainder;
	char	*str;

	str = NULL;
	while (1)
	{
		remainder = nbr % 16;
		str = str_append_char(str, base[remainder]);
		nbr = nbr / 16;
		if (nbr == 0)
			break ;
	}
	str = reverse_str(str);
	return (str);
}

t_flags	set_flags_default(void)
{
	t_flags	flag;

	flag.minus = -1;
	flag.zero = -1;
	flag.hashtag = -1;
	flag.space = -1;
	flag.sign = -1;
	flag.width = -1;
	flag.precision = -1;
	return (flag);
}
