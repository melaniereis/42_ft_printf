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

int main(void)
{
    int ft_len;
    int printf_len;

    // Test string
    ft_len = ft_printf("String: %s\n", "Hello, world!");
    printf_len = printf("String: %s\n", "Hello, world!");
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test character
    ft_len = ft_printf("Character: %c\n", 'A');
    printf_len = printf("Character: %c\n", 'A');
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test integer
    ft_len = ft_printf("Integer: %d\n", 42);
    printf_len = printf("Integer: %d\n", 42);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test negative integer
    ft_len = ft_printf("Negative integer: %i\n", -42);
    printf_len = printf("Negative integer: %i\n", -42);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test unsigned integer
    ft_len = ft_printf("Unsigned integer: %u\n", 4294967295U);
    printf_len = printf("Unsigned integer: %u\n", 4294967295U);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test hexadecimal (lowercase)
    ft_len = ft_printf("Hexadecimal (lowercase): %x\n", 255);
    printf_len = printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test hexadecimal (uppercase)
    ft_len = ft_printf("Hexadecimal (uppercase): %X\n", 255);
    printf_len = printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test pointer
    int num = 42;
    ft_len = ft_printf("Pointer: %p\n", (void *)&num);
    printf_len = printf("Pointer: %p\n", (void *)&num);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test percent sign
    ft_len = ft_printf("Percent sign: %%\n");
    printf_len = printf("Percent sign: %%\n");
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test multiple conversions
    ft_len = ft_printf("Multiple: %s %c %d %i %u %x %X %p %%\n",
                       "test", 'Z', 42, -42, 4294967295U, 255, 255, (void *)&num);
    
    printf_len = printf("Multiple: %s %c %d %i %u %x %X %p %%\n",
                        "test", 'Z', 42, -42, 4294967295U, 255, 255, (void *)&num);
    
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Test edge cases
    ft_len = ft_printf("Null string: %s\n", NULL);
    printf_len = printf("Null string: %s\n", NULL);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    // Testing INT_MAX and INT_MIN for signed integers
    ft_len = ft_printf("INT_MAX: %d\n", INT_MAX);
    printf_len = printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    ft_len = ft_printf("INT_MIN: %d\n", INT_MIN);
    printf_len = printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("ft_printf length: %d, printf length: %d\n\n", ft_len, printf_len);

    return (0);
}