/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:10 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/07 11:24:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./incs/ft_printf.h"
#include <limits.h>

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
    
    char *str_null = NULL;
    ft_len = ft_printf("NULL string: %s\n", str_null);
    printf_len = printf("NULL string: %s\n", str_null);
    check_test(ft_len, printf_len, "NULL string");

    ft_len = ft_printf("Normal string: %s\n", "Hello, world!");
    printf_len = printf("Normal string: %s\n", "Hello, world!");
    check_test(ft_len, printf_len, "Normal string");

    ft_len = ft_printf("Very long string: %s\n", "This is a very long string that goes on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on");
    printf_len = printf("Very long string: %s\n", "This is a very long string that goes on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on and on");
    check_test(ft_len, printf_len, "Very long string");

    print_header("Character tests");
    ft_len = ft_printf("Normal char: %c\n", 'A');
    printf_len = printf("Normal char: %c\n", 'A');
    check_test(ft_len, printf_len, "Normal char");

    ft_len = ft_printf("Null char: %c\n", 0);
    printf_len = printf("Null char: %c\n", 0);
    check_test(ft_len, printf_len, "Null char");

    ft_len = ft_printf("Non-printable char: %c\n", 31);
    printf_len = printf("Non-printable char: %c\n", 31);
    check_test(ft_len, printf_len, "Non-printable char");

    ft_len = ft_printf("Max char: %c\n", 127);
    printf_len = printf("Max char: %c\n", 127);
    check_test(ft_len, printf_len, "Max char");

    print_header("Integer tests");
    ft_len = ft_printf("Zero: %d %i\n", 0, 0);
    printf_len = printf("Zero: %d %i\n", 0, 0);
    check_test(ft_len, printf_len, "Zero");

    ft_len = ft_printf("Positive: %d %i\n", 42, 42);
    printf_len = printf("Positive: %d %i\n", 42, 42);
    check_test(ft_len, printf_len, "Positive");

    ft_len = ft_printf("Negative: %d %i\n", -42, -42);
    printf_len = printf("Negative: %d %i\n", -42, -42);
    check_test(ft_len, printf_len, "Negative");

    ft_len = ft_printf("INT_MAX: %d %i\n", INT_MAX, INT_MAX);
    printf_len = printf("INT_MAX: %d %i\n", INT_MAX, INT_MAX);
    check_test(ft_len, printf_len, "INT_MAX");

    ft_len = ft_printf("INT_MIN: %d %i\n", INT_MIN, INT_MIN);
    printf_len = printf("INT_MIN: %d %i\n", INT_MIN, INT_MIN);
    check_test(ft_len, printf_len, "INT_MIN");

    ft_len = ft_printf("Negative zero: %d %i\n", -0, -0);
    printf_len = printf("Negative zero: %d %i\n", -0, -0);
    check_test(ft_len, printf_len, "Negative zero");

    print_header("Unsigned tests");
    ft_len = ft_printf("Zero: %u\n", 0);
    printf_len = printf("Zero: %u\n", 0);
    check_test(ft_len, printf_len, "Unsigned Zero");

    ft_len = ft_printf("Positive: %u\n", 42);
    printf_len = printf("Positive: %u\n", 42);
    check_test(ft_len, printf_len, "Unsigned Positive");

    ft_len = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    printf_len = printf("UINT_MAX: %u\n", UINT_MAX);
    check_test(ft_len, printf_len, "UINT_MAX");

    ft_len = ft_printf("Negative as unsigned: %u\n", -1);
    printf_len = printf("Negative as unsigned: %u\n", -1);
    check_test(ft_len, printf_len, "Negative as unsigned");

    print_header("Hexadecimal tests");
    ft_len = ft_printf("Zero: %x %X\n", 0, 0);
    printf_len = printf("Zero: %x %X\n", 0, 0);
    check_test(ft_len, printf_len, "Hexadecimal Zero");

    ft_len = ft_printf("Normal: %x %X\n", 42, 42);
    printf_len = printf("Normal: %x %X\n", 42, 42);
    check_test(ft_len, printf_len, "Hexadecimal Normal");

    ft_len = ft_printf("UINT_MAX: %x %X\n", UINT_MAX, UINT_MAX);
    printf_len = printf("UINT_MAX: %x %X\n", UINT_MAX, UINT_MAX);
    check_test(ft_len, printf_len, "UINT_MAX hex");

    ft_len = ft_printf("Negative as hex: %x %X\n", -1, -1);
    printf_len = printf("Negative as hex: %x %X\n", -1, -1);
    check_test(ft_len, printf_len, "Negative as hex");

    print_header("Pointer tests");
    int num = 42;
    void *ptr = &num;
    ft_len = ft_printf("Normal pointer: %p\n", ptr);
    printf_len = printf("Normal pointer: %p\n", ptr);
    check_test(ft_len, printf_len, "Normal pointer");

    ft_len = ft_printf("NULL pointer: %p\n", NULL);
    printf_len = printf("NULL pointer: %p\n", NULL);
    check_test(ft_len, printf_len, "NULL pointer");

    ft_len = ft_printf("Zero as pointer: %p\n", (void *)0);
    printf_len = printf("Zero as pointer: %p\n", (void *)0);
    check_test(ft_len, printf_len, "Zero as pointer");

    ft_len = ft_printf("Function pointer: %p\n", (void *)&main);
    printf_len = printf("Function pointer: %p\n", (void *)&main);
    check_test(ft_len, printf_len, "Function pointer");

    char arr[10];
    ft_len = ft_printf("Array pointer: %p\n", (void *)arr);
    printf_len = printf("Array pointer: %p\n", (void *)arr);
    check_test(ft_len, printf_len, "Array pointer");

    ft_len = ft_printf("Large address: %p\n", (void *)-1);
    printf_len = printf("Large address: %p\n", (void *)-1);
    check_test(ft_len, printf_len, "Large address");

    ft_len = ft_printf("Multiple pointers: %p %p %p\n", ptr, (void *)0, (void *)-1);
    printf_len = printf("Multiple pointers: %p %p %p\n", ptr, (void *)0, (void *)-1);
    check_test(ft_len, printf_len, "Multiple pointers");

    print_header("Percent sign test");
    ft_len = ft_printf("Percent: %%\n");
    printf_len = printf("Percent: %%\n");
    check_test(ft_len, printf_len, "Percent sign");

    ft_len = ft_printf("Multiple percent: %%%%%%\n");
    printf_len = printf("Multiple percent: %%%%%%\n");
    check_test(ft_len, printf_len, "Multiple percent signs");

    print_header("Mixed and edge cases");
    ft_len = ft_printf("Mixed: %s %c %p %d %i %u %x %X %%\n", 
        "test", 'Z', ptr, 42, -42, 42, 42, 42);
    printf_len = printf("Mixed: %s %c %p %d %i %u %x %X %%\n", 
        "test", 'Z', ptr, 42, -42, 42, 42, 42);
    check_test(ft_len, printf_len, "Mixed format");

    ft_len = ft_printf("Complex mix: %d%x%p%s%c%u%%\n", INT_MIN, UINT_MAX, NULL, "test", 'Z', UINT_MAX);
    printf_len = printf("Complex mix: %d%x%p%s%c%u%%\n", INT_MIN, UINT_MAX, NULL, "test", 'Z', UINT_MAX);
    check_test(ft_len, printf_len, "Complex mixed format");

    ft_len = ft_printf("%d%i%u%x%X%c%s%%\n", INT_MIN, INT_MAX, UINT_MAX, 0, UINT_MAX, 0, "");
    printf_len = printf("%d%i%u%x%X%c%s%%\n", INT_MIN, INT_MAX, UINT_MAX, 0, UINT_MAX, 0, "");
    check_test(ft_len, printf_len, "All types mixed");

    ft_len = ft_printf("%c%c%c%c%c\n", 0, 'a', 127, 128, 255);
    printf_len = printf("%c%c%c%c%c\n", 0, 'a', 127, 128, 255);
    check_test(ft_len, printf_len, "Char edge cases");

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
