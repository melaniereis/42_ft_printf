# 42_ft_printf

## Project Overview

ft_printf is a custom implementation of the printf function, a core project in the 42 school curriculum. This project aims to recreate the functionality of the standard C library's printf function, enhancing understanding of variadic functions, string formatting, and output handling.

## Features

- Implements the following conversions:
  - `%c`: Character
  - `%s`: String
  - `%p`: Pointer address
  - `%d` and `%i`: Signed decimal integer
  - `%u`: Unsigned decimal integer
  - `%x` and `%X`: Unsigned hexadecimal integer (lowercase and uppercase)
  - `%%`: Percent sign

- Handles the following flags:
  - `-`: Left-justify within the given field width
  - `0`: Left-pads the number with zeroes instead of spaces
  - `.`: Precision specification
  - `*`: The width or precision is specified in the next argument

## Usage

1. Clone the repository:
git clone https://github.com/yourusername/ft_printf.git

text

2. Compile the library:

make

text

3. Include the header in your C file:

#include "ft_printf.h"

4. Compile your program with the library:

gcc your_program.c libftprintf.a

5. Use ft_printf in your code:

ft_printf("Hello, %s! The answer is %d.\n", "world", 42);

Examples

ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "Hello, world!");
ft_printf("Pointer: %p\n", (void *)0x12345678);
ft_printf("Integer: %d\n", 42);
ft_printf("Unsigned: %u\n", 4294967295);
ft_printf("Hexadecimal: %x\n", 255);
ft_printf("Percentage: %%\n");

Project Structure

    ft_printf.c: Main function implementation
    ft_printf.h: Header file with function prototypes
    utils/: Folder containing utility functions
    Makefile: Compilation rules

Norminette
This project adheres to the Norm, the coding standard of 42 school. All files pass the Norminette check.
Author
Melanie Reis
License
This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

    42 school for the project subject and guidelines
    The C Programming Language by Brian Kernighan and Dennis Ritchie
