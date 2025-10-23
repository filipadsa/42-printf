# 🖨️ ft_printf

A custom implementation of the standard C library `printf()` function.

## 🧠 Overview

`ft_printf` is a recreation of the `printf()` function from libc. It handles formatted output with support for multiple conversion specifiers and variadic arguments, mimicking the behavior of the original `printf()`.

## ⚙️ How It Works

The function parses a format string and replaces conversion specifiers with their corresponding arguments, handling:
- Multiple data types (characters, strings, integers, pointers, etc.)
- Hexadecimal conversions (lowercase and uppercase)
- Return value (number of characters printed)

## 🎯 Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints pointer address in hexadecimal format |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (base 16) lowercase |
| `%X` | Prints a number in hexadecimal (base 16) uppercase |
| `%%` | Prints a percent sign |

## 🌟 Bonus Features

- Flag combinations: `-`, `0`, `.` with field minimum width
- Additional flags: `#`, `+`, ` ` (space)

## 🧪 Usage

Clone and compile:
```bash
git clone https://github.com/filipadsa/42-ft_printf.git
cd 42-ft_printf
make # or 'make bonus' for bonus features
```

Include it in your C project:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
cc main.c libftprintf.a
./a.out
```

Example usage:
```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d | Hex: %x\n", 42, 42);
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Unsigned: %u\n", 4294967295u);
    ft_printf("Uppercase hex: %X\n", 255);
    ft_printf("Characters printed: %d\n", count);
    return (0);
}
```

## 📝 Notes

- All functions follow the **42 Norminette** coding standard;
- Only allowed external functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`;
- Library created using `ar` command (no `libtool`);
- Does **not** implement the original printf()'s buffer management.
