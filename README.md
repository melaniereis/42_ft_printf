# 🌟 42_ft_printf

<div align="center">

![C Logo](https://upload.wikimedia.org/wikipedia/commons/1/19/C_Programming_Language.svg)  <!-- C Programming Language Logo -->

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Norminette](https://img.shields.io/badge/norminette-passing-brightgreen.svg)](https://github.com/42School/norminette)

[Overview](#-project-overview) •
[Features](#-features) •
[Quick Start](#-quick-start-guide) •
[Examples](#-example-usages) •
[Author](#-author)

</div>

## 📖 Project Overview

<details>
<summary>Click to expand</summary>

**ft_printf** is a custom implementation of the `printf` function, a fundamental project in the **42 School** curriculum. This project is designed to recreate the functionality of the standard C library's `printf` function, allowing you to deepen your understanding of:

- Variadic functions
- String formatting
- Output handling

</details>

## ✨ Features

<details>
<summary>Supported Conversions</summary>

| Conversion | Description                               |
|------------|-------------------------------------------|
| `%c`      | Character                                  |
| `%s`      | String                                     |
| `%p`      | Pointer address                            |
| `%d` / `%i` | Signed decimal integer                     |
| `%u`      | Unsigned decimal integer                   |
| `%x` / `%X` | Unsigned hexadecimal integer (lowercase and uppercase) |
| `%%`      | Percent sign                              |

</details>

<details>
<summary>Supported Flags</summary>

- **`-`**: Left-justify within the given field width
- **`0`**: Left-pads the number with zeroes instead of spaces
- **`.`**: Precision specification
- **`*`**: The width or precision is specified in the next argument

</details>

## 🚀 Quick Start Guide

<details>
<summary>Installation Steps</summary>

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/ft_printf.git

2. Navigate into the directory:

    bash
    cd ft_printf

3. Compile the library:

bash
make

4. Include the header in your C file:

#include "ft_printf.h"

5. Compile your program with the library:

bash
gcc your_program.c libftprintf.a

6. Use ft_printf in your code:

ft_printf("Hello, %s! The answer is %d.\n", "world", 42);

</details>
💡 Example Usages
<details> <summary>Click to see code examples</summary>

c
ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "Hello, world!");
ft_printf("Pointer: %p\n", (void *)0x12345678);
ft_printf("Integer: %d\n", 42);
ft_printf("Unsigned: %u\n", 4294967295);
ft_printf("Hexadecimal (lowercase): %x\n", 255);
ft_printf("Hexadecimal (uppercase): %X\n", 255);
ft_printf("Percentage: %%\n");

</details>
📁 Project Structure
<details> <summary>File Structure</summary>

text
.
├── ft_printf.c          # Main function implementation
├── ft_printf.h          # Header file with function prototypes
├── utils/               # Folder containing utility functions
└── Makefile             # Compilation rules

</details>
📏 Norminette Compliance
This project adheres to the Norm, the coding standard of 42 School. All files pass the Norminette check, ensuring clean and maintainable code.
👩‍💻 Author
Melanie Reis <details> <summary>Contact Information</summary>

    GitHub: @YourGitHubUsername
    LinkedIn: Melanie Reis

</details>
📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
🙏 Acknowledgments

    Special thanks to 42 School for providing this project subject and guidelines.
    Inspired by The C Programming Language by Brian Kernighan and Dennis Ritchie.

<details> <summary>📚 Additional Resources</summary>

    C Programming Language Reference
    42 School Official Website
    Understanding Variadic Functions in C

</details>
