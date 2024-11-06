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

static int total_tests = 0;
static int failed_tests = 0;

static void print_header(const char *title)
{
    ft_printf("%s=== %s ===%s\n", BHBLU, title, RESET);
}

static void check_test(int ft_len, int printf_len, const char *test_name)
{
    total_tests++;
    if (ft_len != printf_len)
    {
        failed_tests++;
        ft_printf("%sTest Failed: %s (ft_printf: %d, printf: %d)%s\n", HRED, test_name, ft_len, printf_len, RESET);
    }
}

int main(void)
{
    int ft_len;
    int printf_len;

    print_header("String tests");
    ft_len = ft_printf("Empty string: %s\n", "");
    printf_len = printf("Empty string: %s\n", "");
    check_test(ft_len, printf_len, "Empty string");

    ft_len = ft_printf("NULL string: %s\n", NULL);
    printf_len = printf("NULL string: %s\n", NULL);
    check_test(ft_len, printf_len, "NULL string");

    ft_len = ft_printf("Normal string: %s\n", "Hello, world!");
    printf_len = printf("Normal string: %s\n", "Hello, world!");
    check_test(ft_len, printf_len, "Normal string");

    print_header("Character tests");
    ft_len = ft_printf("Normal char: %c\n", 'A');
    printf_len = printf("Normal char: %c\n", 'A');
    check_test(ft_len, printf_len, "Normal char");

    ft_len = ft_printf("Number as char: %c\n", 65);
    printf_len = printf("Number as char: %c\n", 65);
    check_test(ft_len, printf_len, "Number as char");

    ft_len = ft_printf("Null char: %c\n", 0);
    printf_len = printf("Null char: %c\n", 0);
    check_test(ft_len, printf_len, "Null char");

    print_header("Pointer tests");
    int n = 42;
    ft_len = ft_printf("Normal pointer: %p\n", (void *)&n);
    printf_len = printf("Normal pointer: %p\n", (void *)&n);
    check_test(ft_len, printf_len, "Normal pointer");

    ft_len = ft_printf("NULL pointer: %p\n", NULL);
    printf_len = printf("NULL pointer: %p\n", NULL);
    check_test(ft_len, printf_len, "NULL pointer");

    print_header("Integer tests");
    ft_len = ft_printf("Zero: %d\n", 0);
    printf_len = printf("Zero: %d\n", 0);
    check_test(ft_len, printf_len, "Zero");

    ft_len = ft_printf("Positive: %d\n", 42);
    printf_len = printf("Positive: %d\n", 42);
    check_test(ft_len, printf_len, "Positive");

    ft_len = ft_printf("Negative: %d\n", -42);
    printf_len = printf("Negative: %d\n", -42);
    check_test(ft_len, printf_len, "Negative");

    ft_len = ft_printf("INT_MAX: %d\n", INT_MAX);
    printf_len = printf("INT_MAX: %d\n", INT_MAX);
    check_test(ft_len, printf_len, "INT_MAX");

    ft_len = ft_printf("INT_MIN: %d\n", INT_MIN);
    printf_len = printf("INT_MIN: %d\n", INT_MIN);
    check_test(ft_len, printf_len, "INT_MIN");

    print_header("Unsigned tests");
    ft_len = ft_printf("Zero: %u\n", 0);
    printf_len = printf("Zero: %u\n", 0);
    check_test(ft_len, printf_len, "Unsigned Zero");

    ft_len = ft_printf("Positive: %u\n", 42);
    printf_len = printf("Positive: %u\n", 42);
    check_test(ft_len, printf_len, "Unsigned Positive");

    ft_len = ft_printf("Large: %u\n", UINT_MAX);
    printf_len = printf("Large: %u\n", UINT_MAX);
    check_test(ft_len, printf_len, "Unsigned Large");

    print_header("Hexadecimal tests");
    ft_len = ft_printf("Zero: %x %X\n", 0, 0);
    printf_len = printf("Zero: %x %X\n", 0, 0);
    check_test(ft_len, printf_len, "Hexadecimal Zero");

    ft_len = ft_printf("Normal: %x %X\n", 42, 42);
    printf_len = printf("Normal: %x %X\n", 42, 42);
    check_test(ft_len, printf_len, "Hexadecimal Normal");

    ft_len = ft_printf("Large: %x %X\n", UINT_MAX, UINT_MAX);
    printf_len = printf("Large: %x %X\n", UINT_MAX, UINT_MAX);
    check_test(ft_len, printf_len, "Hexadecimal Large");

    print_header("Percent sign test");
    ft_len = ft_printf("Percent: %%\n");
    printf_len = printf("Percent: %%\n");
    check_test(ft_len, printf_len, "Percent sign");

    print_header("Mixed test");
    ft_len = ft_printf("Mixed: %s %c %p %d %i %u %x %X %%\n", 
        "test", 'Z', (void *)42, 42, -42, 42, 42, 42);
    printf_len = printf("Mixed: %s %c %p %d %i %u %x %X %%\n", 
        "test", 'Z', (void *)42, 42, -42, 42, 42, 42);
    check_test(ft_len, printf_len, "Mixed format");

    // Summary
    ft_printf("\n%s=== Summary ===%s\n", BHBLU, RESET);
    ft_printf("Total tests: %d\n", total_tests);
    ft_printf("Failed tests: %d\n", failed_tests);

    if (failed_tests == 0)
    {
        ft_printf("%sAll tests passed!%s\n", HGRN, RESET);
    }
    else
    {
        ft_printf("%sSome tests failed. Please review the output above.%s\n", HRED, RESET);
    }

    return (0);
}