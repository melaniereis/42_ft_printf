//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:23:14 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/05 11:30:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incs/ft_printf.h"
#include <limits.h>
#include <float.h>

static void	print_header(const char *title)
{
	printf("\n%s%s=== %s ===%s\n", BHCYN, CYNB, title, RESET);
}

static void	print_test_result(int ft_len, int printf_len)
{
	if (ft_len == printf_len)
		printf("%sft_printf return: %d, printf return: %d%s\n",
			BGRN, ft_len, printf_len, RESET);
	else
		printf("%sft_printf return: %d, printf return: %d%s\n",
			BRED, ft_len, printf_len, RESET);
}

static void	test_string(void)
{
	print_header("String Conversion");
	print_test_result(ft_printf("String: %s\n", "Hello, world!"),
					  printf("String: %s\n", "Hello, world!"));
	print_test_result(ft_printf("Empty string: %s\n", ""),
					  printf("Empty string: %s\n", ""));
	print_test_result(ft_printf("NULL string: %s\n", (char *)NULL),
					  printf("NULL string: %s\n", (char *)NULL));
}

static void	test_char(void)
{
	print_header("Character Conversion");
	print_test_result(ft_printf("Character: %c\n", 'A'),
					  printf("Character: %c\n", 'A'));
	print_test_result(ft_printf("Non-printable: %c\n", 7),
					  printf("Non-printable: %c\n", 7));
	print_test_result(ft_printf("Null character: %c\n", 0),
					  printf("Null character: %c\n", 0));
}

static void	test_integer(void)
{
	print_header("Integer Conversion");
	print_test_result(ft_printf("Positive: %d\n", 42),
					  printf("Positive: %d\n", 42));
	print_test_result(ft_printf("Negative: %d\n", -42),
					  printf("Negative: %d\n", -42));
	print_test_result(ft_printf("Zero: %d\n", 0),
					  printf("Zero: %d\n", 0));
	print_test_result(ft_printf("INT_MAX: %d\n", INT_MAX),
					  printf("INT_MAX: %d\n", INT_MAX));
	print_test_result(ft_printf("INT_MIN: %d\n", INT_MIN),
					  printf("INT_MIN: %d\n", INT_MIN));
}

static void	test_unsigned(void)
{
	print_header("Unsigned Integer Conversion");
	print_test_result(ft_printf("Unsigned: %u\n", 4294967295U),
					  printf("Unsigned: %u\n", 4294967295U));
	print_test_result(ft_printf("Zero: %u\n", 0),
					  printf("Zero: %u\n", 0));
	print_test_result(ft_printf("UINT_MAX: %u\n", UINT_MAX),
					  printf("UINT_MAX: %u\n", UINT_MAX));
}

static void	test_hex(void)
{
	print_header("Hexadecimal Conversion");
	print_test_result(ft_printf("Lowercase: %x\n", 255),
					  printf("Lowercase: %x\n", 255));
	print_test_result(ft_printf("Uppercase: %X\n", 255),
					  printf("Uppercase: %X\n", 255));
	print_test_result(ft_printf("Zero: %x\n", 0),
					  printf("Zero: %x\n", 0));
	print_test_result(ft_printf("INT_MAX: %x\n", INT_MAX),
					  printf("INT_MAX: %x\n", INT_MAX));
}

static void	test_pointer(void)
{
	int	num;
	char	*str;

	num = 42;
	str = "test";
	print_header("Pointer Conversion");
	print_test_result(ft_printf("Integer pointer: %p\n", (void *)&num),
					  printf("Integer pointer: %p\n", (void *)&num));
	print_test_result(ft_printf("String pointer: %p\n", (void *)str),
					  printf("String pointer: %p\n", (void *)str));
	print_test_result(ft_printf("NULL pointer: %p\n", NULL),
					  printf("NULL pointer: %p\n", NULL));
}

static void	test_percent(void)
{
	print_header("Percent Sign");
	print_test_result(ft_printf("Percent: %%\n"),
					  printf("Percent: %%\n"));
	print_test_result(ft_printf("Multiple percent: %% %% %%\n"),
					  printf("Multiple percent: %% %% %%\n"));
}

static void	test_multiple(void)
{
	int	num;

	num = 42;
	print_header("Multiple Conversions");
	print_test_result(ft_printf("Multiple: %s %c %d %u %x %X %p %%\n",
			"test", 'Z', -42, 3000000000U, (unsigned int)3735928559, (unsigned int)3735928559, (void *)&num),
			printf("Multiple: %s %c %d %u %x %X %p %%\n",
			"test", 'Z', -42, 3000000000U, (unsigned int)3735928559, (unsigned int)3735928559, (void *)&num));
}

static void	test_edge_cases(void)
{
	print_header("Edge Cases");
	print_test_result(ft_printf("Edge cases: %d %d %u %x\n", INT_MAX, INT_MIN, UINT_MAX, 0),
					  printf("Edge cases: %d %d %u %x\n", INT_MAX, INT_MIN, UINT_MAX, 0));
	print_test_result(ft_printf("Mixed types: %d %u %x %X\n", -1, -1, -1, -1),
					  printf("Mixed types: %d %u %x %X\n", -1, -1, -1, -1));
}

static void	test_precision(void)
{
	print_header("Precision Tests");
	print_test_result(ft_printf("Precision integer: %.5d\n", 42),
					  printf("Precision integer: %.5d\n", 42));
	print_test_result(ft_printf("Precision string: %.3s\n", "Hello"),
					  printf("Precision string: %.3s\n", "Hello"));
	print_test_result(ft_printf("Zero precision: %.0d\n", 0),
					  printf("Zero precision: %.0d\n", 0));
}

int	main(void)
{
	test_string();
	test_char();
	test_integer();
	test_unsigned();
	test_hex();
	test_pointer();
	test_percent();
	test_multiple();
	test_edge_cases();
	test_precision();
	printf("\n%s%sTesting completed!%s\n", BHGRN, GRNB, RESET);
	return (0);
}
