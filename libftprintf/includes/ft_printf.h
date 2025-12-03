/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:42:21 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/02 15:35:13 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		hashtag;
	int		space;
	int		sign;
	int		width;
	int		precision;
}	t_flags;

int		ft_printf(const char *str, ...);
char	*str_append_char(char *dest, const char c);
int		check_if_conversion(const char c);
int		set_flags(t_flags *flag, const char *str, int i);
int		print_char(t_flags flag, va_list ap);
int		print_int(t_flags flag, va_list ap);
int		print_string(t_flags flag, va_list ap);
int		print_pointer(t_flags flag, va_list ap);
int		print_hex(t_flags flag, va_list ap, char *base);
int		print_uint(t_flags flag, va_list ap);
int		print(char *str, int minus, int nb1, int nb2);
int		print_percent(void);
int		check_if_flag(const char c);
int		check_parameter(va_list ap, const char *str, int i, int *lenprintf);
int		set_width_precision(t_flags *flag, const char *str, int i, char *nbr);
char	*strcat_free(char *s1, char *s2);
char	*hex_converter(unsigned long long nbr, char *base);
char	*int_conditions(t_flags *flag, char *nbr);
char	*add_precision(char *str, int precision);
char	*fill_nbr_precision(char *nbr, int precision, int sign);
char	*fill_nbr_sign(char *nbr, int space);

t_flags	set_flags_default(void);

#endif