/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:00:00 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 11:53:42 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	test_basic(void)
{
	int	ft, real;

	printf("\n========== BASIC TESTS ==========\n");

	printf("\n--- %%c (char) ---\n");
	ft = ft_printf("ft: |%04d|\n", 12356677);
	real = printf("rl: |%04d|\n", 12356677);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%s (string) ---\n");
	ft = ft_printf("ft: |%s|\n", "Hello");
	real = printf("rl: |%s|\n", "Hello");
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%p (pointer) ---\n");
	ft = ft_printf("ft: |%p|\n", (void *)0x7fff);
	real = printf("rl: |%p|\n", (void *)0x7fff);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%d (decimal) ---\n");
	ft = ft_printf("ft: |%d|\n", -42);
	real = printf("rl: |%d|\n", -42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%i (integer) ---\n");
	ft = ft_printf("ft: |%i|\n", 42);
	real = printf("rl: |%i|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%u (unsigned) ---\n");
	ft = ft_printf("ft: |%u|\n", 4294967295U);
	real = printf("rl: |%u|\n", 4294967295U);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%x (hex lower) ---\n");
	ft = ft_printf("ft: |%x|\n", 255);
	real = printf("rl: |%x|\n", 255);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%X (hex upper) ---\n");
	ft = ft_printf("ft: |%X|\n", 255);
	real = printf("rl: |%X|\n", 255);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- %%%% (percent) ---\n");
	ft = ft_printf("ft: |%%|\n");
	real = printf("rl: |%%|\n");
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_width(void)
{
	int	ft, real;

	printf("\n========== WIDTH TESTS ==========\n");

	printf("\n--- Width with number (%%5d) ---\n");
	ft = ft_printf("ft: |%5d|\n", 42);
	real = printf("rl: |%5d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Width with string (%%10s) ---\n");
	ft = ft_printf("ft: |%10s|\n", "Hi");
	real = printf("rl: |%10s|\n", "Hi");
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Width with char (%%5c) ---\n");
	ft = ft_printf("ft: |%5c|\n", 'X');
	real = printf("rl: |%5c|\n", 'X');
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Width with hex (%%8x) ---\n");
	ft = ft_printf("ft: |%8x|\n", 42);
	real = printf("rl: |%8x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_minus_flag(void)
{
	int	ft, real;

	printf("\n========== MINUS FLAG TESTS ==========\n");

	printf("\n--- Left align number (%%-5d) ---\n");
	ft = ft_printf("ft: |%-5d|\n", 42);
	real = printf("rl: |%-5d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Left align string (%%-10s) ---\n");
	ft = ft_printf("ft: |%-10s|\n", "Hi");
	real = printf("rl: |%-10s|\n", "Hi");
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Left align hex (%%-8x) ---\n");
	ft = ft_printf("ft: |%-8x|\n", 42);
	real = printf("rl: |%-8x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_zero_flag(void)
{
	int	ft, real;

	printf("\n========== ZERO FLAG TESTS ==========\n");

	printf("\n--- Zero padding (%%05d) ---\n");
	ft = ft_printf("ft: |%05d|\n", 42);
	real = printf("rl: |%05d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Zero with negative (%%05d) ---\n");
	ft = ft_printf("ft: |%05d|\n", -42);
	real = printf("rl: |%05d|\n", -42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Zero with hex (%%08x) ---\n");
	ft = ft_printf("ft: |%08x|\n", 42);
	real = printf("rl: |%08x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_precision(void)
{
	int	ft, real;

	printf("\n========== PRECISION TESTS ==========\n");

	printf("\n--- Precision with number (%%.5d) ---\n");
	ft = ft_printf("ft: |%.5d|\n", 42);
	real = printf("rl: |%.5d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Precision with string (%%.3s) ---\n");
	ft = ft_printf("ft: |%.3s|\n", "Hello");
	real = printf("rl: |%.3s|\n", "Hello");
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Precision with hex (%%.6x) ---\n");
	ft = ft_printf("ft: |%.6x|\n", 42);
	real = printf("rl: |%.6x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Precision .0 with 0 (%%.0d) ---\n");
	ft = ft_printf("ft: |%.0d|\n", 0);
	real = printf("rl: |%.0d|\n", 0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_sign_flags(void)
{
	int	ft, real;

	printf("\n========== SIGN FLAGS TESTS ==========\n");

	printf("\n--- Plus flag (%%+d) ---\n");
	ft = ft_printf("ft: |%+d|\n", 42);
	real = printf("rl: |%+d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Plus with negative (%%+d) ---\n");
	ft = ft_printf("ft: |%+d|\n", -42);
	real = printf("rl: |%+d|\n", -42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Space flag (%% d) ---\n");
	ft = ft_printf("ft: |% d|\n", 42);
	real = printf("rl: |% d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Space with negative (%% d) ---\n");
	ft = ft_printf("ft: |% d|\n", -42);
	real = printf("rl: |% d|\n", -42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_sharp_flag(void)
{
	int	ft, real;

	printf("\n========== SHARP FLAG TESTS ==========\n");

	printf("\n--- Sharp with hex (%%#x) ---\n");
	ft = ft_printf("ft: |%#x|\n", 42);
	real = printf("rl: |%#x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Sharp with HEX (%%#X) ---\n");
	ft = ft_printf("ft: |%#X|\n", 42);
	real = printf("rl: |%#X|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Sharp with 0 (%%#x) ---\n");
	ft = ft_printf("ft: |%#x|\n", 0);
	real = printf("rl: |%#x|\n", 0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_combined(void)
{
	int	ft, real;

	printf("\n========== COMBINED FLAGS TESTS ==========\n");

	printf("\n--- Width + precision (%%8.5d) ---\n");
	ft = ft_printf("ft: |%8.5d|\n", 42);
	real = printf("rl: |%8.5d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Minus + width (%%-8.5d) ---\n");
	ft = ft_printf("ft: |%-8.5d|\n", 42);
	real = printf("rl: |%-8.5d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Plus + zero + width (%%+08d) ---\n");
	ft = ft_printf("ft: |%+08d|\n", 42);
	real = printf("rl: |%+08d|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Sharp + width + precision (%%#10.6x) ---\n");
	ft = ft_printf("ft: |%#10.6x|\n", 42);
	real = printf("rl: |%#10.6x|\n", 42);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- Complex (%%0014.2x) ---\n");
	ft = ft_printf("ft: |%0014.2x|\n", -1);
	real = printf("rl: |%0014.2x|\n", -1);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

void	test_null(void)
{
	int	ft, real;

	printf("\n========== NULL TESTS ==========\n");

	printf("\n--- NULL pointer ---\n");
	ft = ft_printf("ft: |%p|\n", (void *)NULL);
	real = printf("rl: |%p|\n", (void *)NULL);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- NULL string with precision ---\n");
	ft = ft_printf("ft: |[%.3s]|\n", (char *)NULL));
	real = printf("rl: |[%.3s]|\n", (char *)NULL));
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- NULL string with width ---\n");
	ft = ft_printf("ft: |[%9.1s]|\n", (char *)NULL);
	real = printf("rl: |[%9.1s]|\n", (char *)NULL);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- NULL precision ---\n");
	ft = ft_printf("ft: |%.3s|\n", (char *)0);
	real = printf("rl: |%.3s|\n", (char *)0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- NULL width ---\n");
	ft = ft_printf("ft: |%3s|\n", (char *)0);
	real = printf("rl: |%3s|\n", (char *)0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
	
	printf("\n--- NIL width ---\n");
	ft = ft_printf("ft: |%3p|\n", (char *)0);
	real = printf("rl: |%3p|\n", (char *)0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");

	printf("\n--- NIL precision ---\n");
	ft = ft_printf("ft: |%.3p|\n", (char *)0);
	real = printf("rl: |%.3p|\n", (char *)0);
	printf("Returns: ft=%d real=%d %s\n", ft, real, ft == real ? "✓" : "✗");
}

int	main(void)
{
	printf("\n");
	printf("╔════════════════════════════════════════╗\n");
	printf("║    FT_PRINTF COMPREHENSIVE TESTER      ║\n");
	printf("╚════════════════════════════════════════╝\n");

	test_basic();
	test_width();
	test_minus_flag();
	test_zero_flag();
	test_precision();
	test_sign_flags();
	test_sharp_flag();
	test_combined();

	printf("\n");
	printf("╔════════════════════════════════════════╗\n");
	printf("║           TESTING COMPLETE!            ║\n");
	printf("╚════════════════════════════════════════╝\n");
	printf("\n");

	return (0);
}
