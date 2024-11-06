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
#include <stdio.h>
#include <limits.h>

static void	print_header(const char *title)
{
	ft_printf("\n%s%s=== %s ===%s\n", BHBLU, BLUB, title, RESET);
}

static void	print_result(const char *label, int result)
{
	ft_printf("%s%s: %s%d%s\n", HCYN, label, HGRN, result, RESET);
}

static void	test_string(void)
{
	int	ft_result;
	int	printf_result;

	print_header("String Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%s\n", "Hello, world!");
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%s\n", "Hello, world!");
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_char(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Character Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%c\n", 'A');
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%c\n", 'A');
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_integer(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Integer Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%d\n", 42);
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%d\n", 42);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_unsigned(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Unsigned Integer Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%u\n", 4294967295U);
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%u\n", 4294967295U);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_hex(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Hexadecimal Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%x %X\n", 255, 255);
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%x %X\n", 255, 255);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_pointer(void)
{
	int	num;
	int	ft_result;
	int	printf_result;

	num = 42;
	print_header("Pointer Conversion");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%p\n", (void *)&num);
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%p\n", (void *)&num);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_percent(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Percent Sign");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%%\n");
	ft_printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%%\n");
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_multiple(void)
{
	int	num;
	int	ft_result;
	int	printf_result;

	num = 42;
	print_header("Multiple Conversions");
	ft_printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%s %c %d %u %x %X %p %%\n",
		"test", 'Z', -42, 3000000000U,
		(unsigned int)3735928559L,
		(unsigned int)3735928559L, (void *)&num);
	printf_result = printf("%s %c %d %u %x %X %p %%\n",
		"test", 'Z', -42, 3000000000U,
		(unsigned int)3735928559L,
		(unsigned int)3735928559L, (void *)&num);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

int	main(void)
{
	ft_printf("%s%sFT_PRINTF TESTER%s\n", BHCYN, CYNHB, RESET);
	test_string();
	test_char();
	test_integer();
	test_unsigned();
	test_hex();
	test_pointer();
	test_percent();
	test_multiple();
	ft_printf("\n%s%sTesting completed!%s\n", BHGRN, GRNHB, RESET);
	return (0);
}
