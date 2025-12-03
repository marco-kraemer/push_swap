/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos2 <msantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:05:43 by msantos2          #+#    #+#             */
/*   Updated: 2025/12/03 14:49:54 by msantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../includes/ft_printf.h"

int		test_p(void)
{
	int	r1;
	int r2;
	size_t a = ULONG_MAX;
	size_t b = -ULONG_MAX;
	void *pa = &a;
	void *pb = &b;
	void *pn = NULL;

	printf("\n===== BASIC =====\n");
	r1 = printf("printf   : |%p| |%p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%p| |%p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== BASIC =====\n");
	r1 = printf("printf   : |%p| |%p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%p| |%p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== NULL POINTER =====\n");
	r1 = printf("printf   : |%p| |%p|\n", pn, pn);
	r2 = ft_printf("ft_printf: |%p| |%p|\n", pn, pn);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== WIDTH =====\n");
	r1 = printf("printf   : |%20p| |%20p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%20p| |%20p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== LEFT ALIGN (MINUS) =====\n");
	r1 = printf("printf   : |%-20p| |%-20p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%-20p| |%-20p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== WIDTH (SMALL) =====\n");
	r1 = printf("printf   : |%5p| |%8p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%5p| |%8p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== LEFT ALIGN WITH SMALL WIDTH =====\n");
	r1 = printf("printf   : |%-5p| |%-8p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%-5p| |%-8p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== LARGE WIDTH =====\n");
	r1 = printf("printf   : |%50p| |%50p|\n", pa, pb);
	r2 = ft_printf("ft_printf: |%50p| |%50p|\n", pa, pb);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== MIXED CASES =====\n");
	r1 = printf("printf   : |%3p| |%-12p| |%15p|\n", pa, pb, pn);
	r2 = ft_printf("ft_printf: |%3p| |%-12p| |%15p|\n", pa, pb, pn);
	printf("Return Value: printf %i ft_printf: %i\n\n", r1, r2);

	printf("\n===== END =====\n");

	return 0;
}

int test_i(void)
{
	int p = 42;
	int n = -42;
	printf("\n===== BASIC =====\n");
	printf("printf   : |%i| |%i|\n", p, n);
	ft_printf("ft_printf: |%i| |%i|\n\n", p, n);
	printf("\n===== WIiTH =====\n");
	printf("printf   : |%10i| |%10i|\n", p, n);
	ft_printf("ft_printf: |%10i| |%10i|\n\n", p, n);
	printf("\n===== PRECISION =====\n");
	printf("printf   : |%.5i| |%.5i|\n", p, n);
	ft_printf("ft_printf: |%.5i| |%.5i|\n\n", p, n);
	printf("\n===== WIiTH + PRECISION =====\n");
	printf("printf   : |%10.5i| |%10.5i|\n", p, n);
	ft_printf("ft_printf: |%10.5i| |%10.5i|\n\n", p, n);
	printf("\n===== ZERO PAiiING =====\n");
	printf("printf   : |%010i| |%010i|\n", p, n);
	ft_printf("ft_printf: |%010i| |%010i|\n\n", p, n);
	printf("\n===== ZERO PAiiING IGNOREi BY PRECISION =====\n");
	printf("printf   : |%010.5i| |%010.5i|\n", p, n);
	ft_printf("ft_printf: |%010.5i| |%010.5i|\n\n", p, n);
	printf("\n===== MINUS (LEFT ALIGN) =====\n");
	printf("printf   : |%-10i| |%-10i|\n", p, n);
	ft_printf("ft_printf: |%-10i| |%-10i|\n\n", p, n);
	printf("\n===== PLUS SIGN =====\n");
	printf("printf   : |%+i| |%+i|\n", p, n);
	ft_printf("ft_printf: |%+i| |%+i|\n\n", p, n);
	printf("\n===== SPACE SIGN =====\n");
	printf("printf   : |% i| |% i|\n", p, n);
	ft_printf("ft_printf: |% i| |% i|\n\n", p, n);
	printf("\n===== PLUS OVERRIiES SPACE =====\n");
	printf("printf   : |%+i| |%+i|\n", p, n);
	ft_printf("ft_printf: |%+i| |%+i|\n\n", p, n);
	printf("\n===== WIiTH < PRECISION =====\n");
	printf("printf   : |%5.10i| |%5.10i|\n", p, n);
	ft_printf("ft_printf: |%5.10i| |%5.10i|\n\n", p, n);
	printf("\n===== PRECISION ZERO (value = 0) =====\n");
	printf("printf   : |%.0i| |%.0i|\n", 0, 1);
	ft_printf("ft_printf: |%.0i| |%.0i|\n\n", 0, 1);
	printf("\n===== WIiTH + PRECISION ZERO + ZERO VALUE =====\n");
	printf("printf   : |%5.0i|\n", 0);
	ft_printf("ft_printf: |%5.0i|\n\n", 0);
	printf("\n===== LARGE WIiTH =====\n");
	printf("printf   : |%30i| |%30i|\n", p, n);
	ft_printf("ft_printf: |%30i| |%30i|\n\n", p, n);
	printf("\n===== LARGE PRECISION =====\n");
	printf("printf   : |%.20i| |%.20i|\n", p, n);
	ft_printf("ft_printf: |%.20i| |%.20i|\n\n", p, n);
	printf("\n===== INT_MIN / INT_MAX =====\n");
	printf("printf   : |%i| |%i|\n", INT_MIN, INT_MAX);
	ft_printf("ft_printf: |%i| |%i|\n\n", INT_MIN, INT_MAX);
	printf("\n===== PLUS + WIiTH + PRECISION =====\n");
	printf("printf   : |%+15.8i| |%+15.8i|\n", p, n);
	ft_printf("ft_printf: |%+15.8i| |%+15.8i|\n\n", p, n);
	printf("\n===== ZERO + WIiTH (valii combo) =====\n");
	printf("printf   : |%020i| |%020i|\n", p, n);
	ft_printf("ft_printf: |%020i| |%020i|\n\n", p, n);
	printf("\n===== FULL COMBO (valii): +, 0, wiith, precision =====\n");
	printf("printf   : |%+020.10i| |%+020.10i|\n", p, n);
	ft_printf("ft_printf: |%+020.10i| |%+020.10i|\n\n", p, n);
	printf("\n===== END =====\n");
	return 0;
}

int test_d(void)
{
	int p = 42;
	int n = -42;
	printf("\n===== BASIC =====\n");
	printf("printf   : |%d| |%d|\n", p, n);
	ft_printf("ft_printf: |%d| |%d|\n\n", p, n);
	printf("\n===== WIDTH =====\n");
	printf("printf   : |%10d| |%10d|\n", p, n);
	ft_printf("ft_printf: |%10d| |%10d|\n\n", p, n);
	printf("\n===== PRECISION =====\n");
	printf("printf   : |%.5d| |%.5d|\n", p, n);
	ft_printf("ft_printf: |%.5d| |%.5d|\n\n", p, n);
	printf("\n===== WIDTH + PRECISION =====\n");
	printf("printf   : |%10.5d| |%10.5d|\n", p, n);
	ft_printf("ft_printf: |%10.5d| |%10.5d|\n\n", p, n);
	printf("\n===== ZERO PADDING =====\n");
	printf("printf   : |%010d| |%010d|\n", p, n);
	ft_printf("ft_printf: |%010d| |%010d|\n\n", p, n);
	printf("\n===== ZERO PADDING IGNORED BY PRECISION =====\n");
	printf("printf   : |%010.5d| |%010.5d|\n", p, n);
	ft_printf("ft_printf: |%010.5d| |%010.5d|\n\n", p, n);
	printf("\n===== MINUS (LEFT ALIGN) =====\n");
	printf("printf   : |%-10d| |%-10d|\n", p, n);
	ft_printf("ft_printf: |%-10d| |%-10d|\n\n", p, n);
	printf("\n===== PLUS SIGN =====\n");
	printf("printf   : |%+d| |%+d|\n", p, n);
	ft_printf("ft_printf: |%+d| |%+d|\n\n", p, n);
	printf("\n===== SPACE SIGN =====\n");
	printf("printf   : |% d| |% d|\n", p, n);
	ft_printf("ft_printf: |% d| |% d|\n\n", p, n);
	printf("\n===== PLUS OVERRIDES SPACE =====\n");
	printf("printf   : |%+d| |%+d|\n", p, n);
	ft_printf("ft_printf: |%+d| |%+d|\n\n", p, n);
	printf("\n===== WIDTH < PRECISION =====\n");
	printf("printf   : |%5.10d| |%5.10d|\n", p, n);
	ft_printf("ft_printf: |%5.10d| |%5.10d|\n\n", p, n);
	printf("\n===== PRECISION ZERO (value = 0) =====\n");
	printf("printf   : |%.0d| |%.0d|\n", 0, 1);
	ft_printf("ft_printf: |%.0d| |%.0d|\n\n", 0, 1);
	printf("\n===== WIDTH + PRECISION ZERO + ZERO VALUE =====\n");
	printf("printf   : |%5.0d|\n", 0);
	ft_printf("ft_printf: |%5.0d|\n\n", 0);
	printf("\n===== LARGE WIDTH =====\n");
	printf("printf   : |%30d| |%30d|\n", p, n);
	ft_printf("ft_printf: |%30d| |%30d|\n\n", p, n);
	printf("\n===== LARGE PRECISION =====\n");
	printf("printf   : |%.20d| |%.20d|\n", p, n);
	ft_printf("ft_printf: |%.20d| |%.20d|\n\n", p, n);
	printf("\n===== INT_MIN / INT_MAX =====\n");
	printf("printf   : |%d| |%d|\n", INT_MIN, INT_MAX);
	ft_printf("ft_printf: |%d| |%d|\n\n", INT_MIN, INT_MAX);
	printf("\n===== PLUS + WIDTH + PRECISION =====\n");
	printf("printf   : |%+15.8d| |%+15.8d|\n", p, n);
	ft_printf("ft_printf: |%+15.8d| |%+15.8d|\n\n", p, n);
	printf("\n===== ZERO + WIDTH (valid combo) =====\n");
	printf("printf   : |%020d| |%020d|\n", p, n);
	ft_printf("ft_printf: |%020d| |%020d|\n\n", p, n);
	printf("\n===== FULL COMBO (valid): +, 0, width, precision =====\n");
	printf("printf   : |%+020.10d| |%+020.10d|\n", p, n);
	ft_printf("ft_printf: |%+020.10d| |%+020.10d|\n\n", p, n);
	printf("\n===== END =====\n");
	return 0;
}
int test_s(void)
{
	char *s1 = "hello";
	char *s2 = "world";
	char *longs = "this is a very long string used for testing";
	char *empty = "";
	char *nulls = NULL;
	printf("\n===== BASIC =====\n");
	printf("printf   : |%s| |%s|\n", s1, s2);
	ft_printf("ft_printf: |%s| |%s|\n\n", s1, s2);
	printf("\n===== NULL STRING =====\n");
	printf("printf   : |%s| |%s|\n", nulls, nulls);
	ft_printf("ft_printf: |%s| |%s|\n\n", nulls, nulls);
	printf("\n===== WIDTH =====\n");
	printf("printf   : |%10s| |%15s|\n", s1, s2);
	ft_printf("ft_printf: |%10s| |%15s|\n\n", s1, s2);
	printf("\n===== LEFT ALIGN (MINUS) =====\n");
	printf("printf   : |%-10s| |%-15s|\n", s1, s2);
	ft_printf("ft_printf: |%-10s| |%-15s|\n\n", s1, s2);
	printf("\n===== PRECISION =====\n");
	printf("printf   : |%.1s| |%.3s| |%.0s|\n", s1, s1, s1);
	ft_printf("ft_printf: |%.1s| |%.3s| |%.0s|\n\n", s1, s1, s1);
	printf("\n===== WIDTH + PRECISION =====\n");
	printf("printf   : |%10.3s| |%15.2s|\n", s1, s2);
	ft_printf("ft_printf: |%10.3s| |%15.2s|\n\n", s1, s2);
	printf("\n===== LEFT ALIGN + PRECISION =====\n");
	printf("printf   : |%-10.3s| |%-15.2s|\n", s1, s2);
	ft_printf("ft_printf: |%-10.3s| |%-15.2s|\n\n", s1, s2);
	printf("\n===== PRECISION > STRING SIZE =====\n");
	printf("printf   : |%.10s| |%.20s|\n", s1, s2);
	ft_printf("ft_printf: |%.10s| |%.20s|\n\n", s1, s2);
	printf("\n===== EMPTY STRING =====\n");
	printf("printf   : |%s| |%.5s| |%10s|\n", empty, empty, empty);
	ft_printf("ft_printf: |%s| |%.5s| |%10s|\n\n", empty, empty, empty);
	printf("\n===== LONG STRING =====\n");
	printf("printf   : |%s|\n", longs);
	ft_printf("ft_printf: |%s|\n\n", longs);
	printf("\n===== LONG STRING WITH WIDTH =====\n");
	printf("printf   : |%50s|\n", longs);
	ft_printf("ft_printf: |%50s|\n\n", longs);
	printf("\n===== LONG STRING WITH PRECISION =====\n");
	printf("printf   : |%.10s| |%.20s|\n", longs, longs);
	ft_printf("ft_printf: |%.10s| |%.20s|\n\n", longs, longs);
	printf("\n===== LONG STRING WITH WIDTH + PRECISION =====\n");
	printf("printf   : |%30.10s| |%40.15s|\n", longs, longs);
	ft_printf("ft_printf: |%30.10s| |%40.15s|\n\n", longs, longs);
	printf("\n===== MIXED CASES =====\n");
	printf("printf   : |%3s| |%-12s| |%15.5s|\n", s1, s2, longs);
	ft_printf("ft_printf: |%3s| |%-12s| |%15.5s|\n\n", s1, s2, longs);
	printf("\n===== END =====\n");
	return 0;
	}

	int	test_x(void)
	{
	unsigned int a = 42;
	unsigned int b = 255;
	unsigned int c = 4095;
	unsigned int zero = 0;
	printf("\n===== BASIC =====\n");
	printf("printf   : |%x| |%X|\n", a, a);
	ft_printf("ft_printf: |%x| |%X|\n\n", a, a);
	printf("\n===== MULTIPLE VALUES =====\n");
	printf("printf   : |%x| |%x| |%X| |%X|\n", a, b, c, c);
	ft_printf("ft_printf: |%x| |%x| |%X| |%X|\n\n", a, b, c, c);
	printf("\n===== ZERO VALUE =====\n");
	printf("printf   : |%x| |%X|\n", zero, zero);
	ft_printf("ft_printf: |%x| |%X|\n\n", zero, zero);
	printf("\n===== WIDTH =====\n");
	printf("printf   : |%10x| |%10X|\n", a, a);
	ft_printf("ft_printf: |%10x| |%10X|\n\n", a, a);
	printf("\n===== MINUS (LEFT ALIGN) =====\n");
	printf("printf   : |%-10x| |%-10X|\n", a, a);
	ft_printf("ft_printf: |%-10x| |%-10X|\n\n", a, a);
	printf("\n===== ZERO PADDING =====\n");
	printf("printf   : |%010x| |%010X|\n", a, a);
	ft_printf("ft_printf: |%010x| |%010X|\n\n", a, a);
	printf("\n===== PRECISION =====\n");
	printf("printf   : |%.5x| |%.8X|\n", a, b);
	ft_printf("ft_printf: |%.5x| |%.8X|\n\n", a, b);
	printf("\n===== WIDTH + PRECISION =====\n");
	printf("printf   : |%10.5x| |%12.8X|\n", a, b);
	ft_printf("ft_printf: |%10.5x| |%12.8X|\n\n", a, b);
	printf("\n===== ZERO PADDING IGNORED IF PRECISION EXISTS =====\n");
	printf("printf   : |%010.5x| |%010.5X|\n", a, a);
	ft_printf("ft_printf: |%010.5x| |%010.5X|\n\n", a, a);
	printf("\n===== HASH (#) PREFIX =====\n");
	printf("printf   : |%#x| |%#X|\n", a, a);
	ft_printf("ft_printf: |%#x| |%#X|\n\n", a, a);
	printf("\n===== HASH WITH ZERO VALUE (no prefix) =====\n");
	printf("printf   : |%#x| |%#X|\n", zero, zero);
	ft_printf("ft_printf: |%#x| |%#X|\n\n", zero, zero);
	printf("\n===== HASH + WIDTH =====\n");
	printf("printf   : |%#10x| |%#10X|\n", a, a);
	ft_printf("ft_printf: |%#10x| |%#10X|\n\n", a, a);
	printf("\n===== HASH + LEFT ALIGN =====\n");
	printf("printf   : |%-#10x| |%-#10X|\n", a, a);
	ft_printf("ft_printf: |%-#10x| |%-#10X|\n\n", a, a);
	printf("\n===== HASH + PRECISION =====\n");
	printf("printf   : |%#.8x| |%#.8X|\n", a, a);
	ft_printf("ft_printf: |%#.8x| |%#.8X|\n\n", a, a);
	printf("\n===== HASH + WIDTH + PRECISION =====\n");
	printf("printf   : |%#15.8x| |%#15.8X|\n", a, a);
	ft_printf("ft_printf: |%#15.8x| |%#15.8X|\n\n", a, a);
	printf("\n===== HASH + ZERO PADDING =====\n");
	printf("printf   : |%#010x| |%#010X|\n", a, a);
	ft_printf("ft_printf: |%#010x| |%#010X|\n\n", a, a);
	printf("\n===== HASH + ZERO PADDING + PRECISION (zero ignored) =====\n");
	printf("printf   : |%#010.6x| |%#010.6X|\n", a, a);
	ft_printf("ft_printf: |%#010.6x| |%#010.6X|\n\n", a, a);
	printf("\n===== LARGE WIDTH =====\n");
	printf("printf   : |%30x| |%30X|\n", c, c);
	ft_printf("ft_printf: |%30x| |%30X|\n\n", c, c);
	printf("\n===== LARGE PRECISION =====\n");
	printf("printf   : |%.20x| |%.20X|\n", c, c);
	ft_printf("ft_printf: |%.20x| |%.20X|\n\n", c, c);
	printf("\n===== MAX_MIN =====\n");
	//    printf("printf   : %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("ft_printf: %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n===== MIXED EXTREME CASES =====\n");
	printf("printf   : |%#20.10x| |%#25.12X|\n", b, c);
	ft_printf("ft_printf: |%#20.10x| |%#25.12X|\n\n", b, c);
	printf("\n===== END =====\n");
	return 0;
}

void	test_u(void)
{
	unsigned int a = 42;
	unsigned int b = 999;
	unsigned int c = UINT_MAX;
	int neg = -1; // Para testar comportamento unsigned
	unsigned int zero = 0;
	printf("\n===== BASIC =====\n");
	printf("printf   : |%u| |%u|\n", a, b);
	ft_printf("ft_printf: |%u| |%u|\n\n", a, b);
	printf("\n===== ZERO VALUE =====\n");
	printf("printf   : |%u| |%u|\n", zero, zero);
	ft_printf("ft_printf: |%u| |%u|\n\n", zero, zero);
	printf("\n===== WIDTH =====\n");
	printf("printf   : |%10u| |%10u|\n", a, b);
	ft_printf("ft_printf: |%10u| |%10u|\n\n", a, b);
	printf("\n===== LEFT ALIGN (MINUS) =====\n");
	printf("printf   : |%-10u| |%-10u|\n", a, b);
	ft_printf("ft_printf: |%-10u| |%-10u|\n\n", a, b);
	printf("\n===== ZERO PADDING =====\n");
	printf("printf   : |%010u| |%010u|\n", a, b);
	ft_printf("ft_printf: |%010u| |%010u|\n\n", a, b);
	printf("\n===== PRECISION =====\n");
	printf("printf   : |%.5u| |%.8u|\n", a, b);
	ft_printf("ft_printf: |%.5u| |%.8u|\n\n", a, b);
	printf("\n===== WIDTH + PRECISION =====\n");
	printf("printf   : |%10.5u| |%12.8u|\n", a, b);
	ft_printf("ft_printf: |%10.5u| |%12.8u|\n\n", a, b);
	printf("\n===== ZERO PADDING IGNORED BY PRECISION =====\n");
	printf("printf   : |%010.5u| |%010.5u|\n", a, b);
	ft_printf("ft_printf: |%010.5u| |%010.5u|\n\n", a, b);
	printf("\n===== PRECISION ZERO (value = 0) =====\n");
	printf("printf   : |%.0u| |%.0u|\n", zero, a);
	ft_printf("ft_printf: |%.0u| |%.0u|\n\n", zero, a);
	printf("\n===== WIDTH + PRECISION ZERO + ZERO VALUE =====\n");
	printf("printf   : |%5.0u| |%8.0u|\n", zero, zero);
	ft_printf("ft_printf: |%5.0u| |%8.0u|\n\n", zero, zero);
	printf("\n===== LARGE WIDTH =====\n");
	printf("printf   : |%30u| |%30u|\n", a, b);
	ft_printf("ft_printf: |%30u| |%30u|\n\n", a, b);
	printf("\n===== LARGE PRECISION =====\n");
	printf("printf   : |%.20u| |%.20u|\n", a, b);
	ft_printf("ft_printf: |%.20u| |%.20u|\n\n", a, b);
	printf("\n===== UNSIGNED BEHAVIOR WITH NEGATIVE INPUT =====\n");
	printf("printf   : |%u| (neg = -1)\n", (unsigned int)neg);
	ft_printf("ft_printf: |%u| (neg = -1)\n\n", (unsigned int)neg);
	printf("\n===== UINT_MAX =====\n");
	printf("printf   : |%u|\n", c);
	ft_printf("ft_printf: |%u|\n\n", c);
	printf("\n===== COMBINED EXTREME CASES =====\n");
	printf("printf   : |%20.10u| |%15.8u|\n", c, b);
	ft_printf("ft_printf: |%20.10u| |%15.8u|\n\n", c, b);
	printf("\n===== FULL VALID COMBO: ZERO + WIDTH + PRECISION =====\n");
	printf("printf   : |%020.10u| |%020.10u|\n", a, b);
	ft_printf("ft_printf: |%020.10u| |%020.10u|\n\n", a, b);
	printf("\n===== END =====\n");
}

void	test_c(void)
{
	char a = 'A';
	char b = 'z';
	char c = '*';
	char zero = '\0'; // character 0

	printf("\n===== BASIC =====\n");
	printf("printf   : %c %c %c\n", a, b, c);
	ft_printf("ft_printf: |%c| |%c| |%c|\n\n", a, b, c);

	printf("\n===== 0 =====\n");
	printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", '0', 0, '1');

	printf("\n===== WIDTH =====\n");
	printf("printf   : |%5c| |%8c|\n", a, b);
	ft_printf("ft_printf: |%5c| |%8c|\n\n", a, b);

	printf("\n===== LEFT ALIGN (MINUS) =====\n");
	printf("printf   : |%-5c| |%-8c|\n", a, b);
	ft_printf("ft_printf: |%-5c| |%-8c|\n\n", a, b);

	printf("\n===== MIXED WIDTH CASES =====\n");
	printf("printf   : |%3c| |%7c| |%10c|\n", a, b, c);
	ft_printf("ft_printf: |%3c| |%7c| |%10c|\n\n", a, b, c);

	printf("\n===== LEFT ALIGN + WIDTH =====\n");
	printf("printf   : |%-3c| |%-7c| |%-10c|\n", a, b, c);
	ft_printf("ft_printf: |%-3c| |%-7c| |%-10c|\n\n", a, b, c);

	printf("\n===== NULL CHARACTER (\\\\0) =====\n");
	printf("printf   : |%c| [visible length=%d]\n", zero, printf("|%c|\n", zero));
	ft_printf("ft_printf: |%c| [visible length=%d]\n\n", zero, ft_printf("|%c|\n", zero));

	printf("\n===== NULL CHARACTER WITH WIDTH =====\n");
	printf("printf   : |%5c| |%-5c|\n", zero, zero);
	ft_printf("ft_printf: |%5c| |%-5c|\n\n", zero, zero);

	printf("\n===== SEQUENTIAL CHARACTERS =====\n");
	printf("printf   : |%c%c%c%c%c|\n", 'H', 'e', 'l', 'l', 'o');
	ft_printf("ft_printf: |%c%c%c%c%c|\n\n", 'H', 'e', 'l', 'l', 'o');

	printf("\n===== EXTENDED ASCII (if platform supports) =====\n");
	printf("printf   : |%c| |%c|\n", (char)128, (char)255);
	ft_printf("ft_printf: |%c| |%c|\n\n", (char)128, (char)255);

	printf("\n===== END =====\n");
}

void	test_return_value()
{
	int r1, r2;
	int i = -42;
	int d = 42;
	long a = LONG_MAX;

	unsigned int u = 999999;
	unsigned int uzero = 0;
	unsigned int umax = UINT_MAX;
	void *p = &a;
	void *pnull = NULL;
	char c = 'A';
	char *s = "Hello";
	char *snull = NULL;
	printf("\n===================== %%c =====================\n");
	r1 = printf("|%5c|\n", c);
	r2 = ft_printf("|%5c|\n", c);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%-5c|\n", c);
	r2 = ft_printf("|%-5c|\n", c);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf(" |%c| |%c| |%c|\n", 0, 0, 0);
	r2 = ft_printf(" |%c| |%c| |%c|\n", 0, 0, 0);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== %%s =====================\n");
	r1 = printf("|%10s|\n", s);
	r2 = ft_printf("|%10s|\n", s);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%-10s|\n", s);
	r2 = ft_printf("|%-10s|\n", s);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%.3s|\n", s);
	r2 = ft_printf("|%.3s|\n", s);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%10.3s|\n", s);
	r2 = ft_printf("|%10.3s|\n", s);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%s|\n", snull);
	r2 = ft_printf("|%s|\n", snull);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== %%p =====================\n");
	r1 = printf("|%20p|\n", p);
	r2 = ft_printf("|%20p|\n", p);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%-20p|\n", p);
	r2 = ft_printf("|%-20p|\n", p);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%p|\n", pnull);
	r2 = ft_printf("|%p|\n", pnull);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== %%d / %%i =====================\n");
	r1 = printf("|%d|\n", i);
	r2 = ft_printf("|%d|\n", i);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%+d|\n", i);
	r2 = ft_printf("|%+d|\n", i);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|% d|\n", d);
	r2 = ft_printf("|% d|\n", d);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%10.5d|\n", i);
	r2 = ft_printf("|%10.5d|\n", i);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%-10d|\n", d);
	r2 = ft_printf("|%-10d|\n", d);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== %%u =====================\n");
	r1 = printf("|%u|\n", u);
	r2 = ft_printf("|%u|\n", u);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%010u|\n", u);
	r2 = ft_printf("|%010u|\n", u);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%.8u|\n", u);
	r2 = ft_printf("|%.8u|\n", u);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%20.10u|\n", uzero);
	r2 = ft_printf("|%20.10u|\n", uzero);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%u|\n", umax);
	r2 = ft_printf("|%u|\n", umax);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== %%x / %%X =====================\n");
	r1 = printf("|%x|\n", 255);
	r2 = ft_printf("|%x|\n", 255);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%#x|\n", 255);
	r2 = ft_printf("|%#x|\n", 255);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%10.6x|\n", 255);
	r2 = ft_printf("|%10.6x|\n", 255);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%-10X|\n", 4095);
	r2 = ft_printf("|%-10X|\n", 4095);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	r1 = printf("|%#20.10X|\n", 4095);
	r2 = ft_printf("|%#20.10X|\n", 4095);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== literal %% =====================\n");
	r1 = printf("|%%|\n");
	r2 = ft_printf("|%%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("\n===================== FULL COMBO =====================\n");
	r1 = printf("|%c|%s|%10d|%-5u|%#x|%p|%%|\n",
					'Z', "ABC", -999, 42u, 255, p);
	r2 = ft_printf("|%c|%s|%10d|%-5u|%#x|%p|%%|\n",
					'Z', "ABC", -999, 42u, 255, p);
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);
	printf("===== END =====\n");
}

void	test_percent(void)
{
	int r1, r2;

	printf("\n===== BASIC =====\n");
	r1 = printf("|%%|\n");
	r2 = ft_printf("|%%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("\n===== WIDTH =====\n");
	r1 = printf("|%5%|\n");
	r2 = ft_printf("|%5%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("\n===== LEFT ALIGN (MINUS) =====\n");
	r1 = printf("|%-5%|\n"); 
	r2 = ft_printf("|%-5%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("\n===== ZERO PADDING =====\n");
	r1 = printf("|%05%|\n"); 
	r2 = ft_printf("|%05%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("\n===== MIXED CASES =====\n");
	r1 = printf("|%3%| |%-8%| |%07%|\n");
	r2 = ft_printf("|%3%| |%-8%| |%07%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("\n===== FULL COMBO: WIDTH + ZERO PADDING =====\n");
	r1 = printf("|%010%|\n");
	r2 = ft_printf("|%010%|\n");
	printf("ret printf   : %d\nret ft_printf: %d\n\n", r1, r2);

	printf("===== END =====\n");
}

void	test_invalid()
{
	printf("\n===== BASIC =====\n");

	ft_printf("%l");
	ft_printf("%i %k", 12, 21);
	ft_printf("%20.12m", 123);
	ft_printf("%   )la 123 lklk 12\n\n\n\n");
	ft_printf("%i %p %l",12,12,12);
}

int main(void)
{
	test_c();
	test_s();
	test_d();
	test_i();
	test_u();
	test_p();
	test_x();
	test_percent();
	test_return_value();
	test_invalid();
}


