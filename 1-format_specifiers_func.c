#include "main.h"

/**
 * _print_binary - Prints the binary value.
 * @args: The arguments list.
 * @buf: Pointer to the buffer_t struct.
 *
 * Return: The number of characters to be printed.
 */

int _print_binary(va_list args, buffer_t *buf)
{

	unsigned int value = va_arg(args, unsigned int);

	return (unsigned_int_to_binary(value, buf));
}

/**
 * _print_o - Prints an octal number.
 * @args: The arguments list.
 * @buf: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_o(va_list args, buffer_t *buf)
{

	unsigned int n = va_arg(args, unsigned int);

	return (octal_to_str(n, buf));
}

/**
 * _print_x - Prints a hexadecimal number (lowercase).
 * @args: The arguments list.
 * @buf: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_x(va_list args, buffer_t *buf)
{

	unsigned int n = va_arg(args, unsigned int);

	return (hex_to_str(n, buf, 0));
}

/**
 * _print_X - Prints a hexadecimal number (uppercase).
 * @args: The arguments list.
 * @buf: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_X(va_list args, buffer_t *buf)
{

	unsigned int n = va_arg(args, unsigned int);

	return (hex_to_str(n, buf, 1));
}
