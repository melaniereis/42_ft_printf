/* ************************************************************************** */
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
	printf("\n%s%s=== %s ===%s\n", BHBLU, BLUB, title, RESET);
}

static void	print_result(const char *label, int result)
{
	printf("%s%s: %s%d%s\n", HCYN, label, HGRN, result, RESET);
}

static void	test_string(void)
{
	int	ft_result;
	int	printf_result;

	print_header("String Conversion");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%s\n", "Hello, world!");
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%s\n", "Hello, world!");
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_char(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Character Conversion");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%c\n", 'A');
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%c\n", 'A');
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_pointer(void)
{
	void	*ptr;
	int		ft_result;
	int		printf_result;

	ptr = (void *)0x12345678;
	print_header("Pointer Conversion");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%p\n", ptr);
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%p\n", ptr);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_integer(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Integer Conversion");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%i, %d\n", 42, -42);
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%i, %d\n", 42, -42);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_hex(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Hexadecimal Conversion");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%x, %X\n", 255, 255);
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%x, %X\n", 255, 255);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_percent(void)
{
	int	ft_result;
	int	printf_result;

	print_header("Percent Sign");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%%\n");
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%%\n");
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

static void	test_multiple(void)
{
	void	*ptr;
	int		ft_result;
	int		printf_result;

	ptr = (void *)0x12345678;
	print_header("Multiple Conversions");
	printf("%sft_printf:%s ", HYEL, RESET);
	ft_result = ft_printf("%s %c %p %i %d %x %X %%\n",
		"test", 'Z', ptr, 42, -42, 255, 255);
	printf("%sprintf:    %s ", HYEL, RESET);
	printf_result = printf("%s %c %p %i %d %x %X %%\n",
		"test", 'Z', ptr, 42, -42, 255, 255);
	print_result("ft_printf return", ft_result);
	print_result("printf return   ", printf_result);
}

int	main(void)
{
	printf("%s%sFT_PRINTF TESTER%s\n", BHCYN, CYNHB, RESET);
	test_string();
	test_char();
	test_pointer();
	test_integer();
	test_hex();
	test_percent();
	test_multiple();
	printf("\n%s%sTesting completed!%s\n", BHGRN, GRNHB, RESET);
	return (0);
}