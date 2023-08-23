#include "main.h"

/**
 * _print_binary - Prints the binary value.
 * @args: The arguments list.
 *
 * Return: The number of characters to be printed.
 */

int _print_binary(va_list args)
{

	unsigned int value = va_arg(args, unsigned int);
	char *binary_representation = unsigned_int_to_binary(value);
	int len;

	if (!binary_representation)
		return (-1);

	len = write(1, binary_representation, strlen(binary_representation));
	free(binary_representation);

	return (len);
}

/**
 * _print_o - Prints an octal number.
 * @args: The arguments list.
 *
 * Return: Number of characters printed.
 */

int _print_o(va_list args)
{

	unsigned int n = va_arg(args, unsigned int);
	char b[66];
	int i;

	char *converted = octal_to_str(n, b);

	for (i = 0; converted[i]; i++)
	{

		write(1, &converted[i], 1);
	}

	return (i);
}

/**
 * _print_x - Prints a hexadecimal number (lowercase).
 * @args: The arguments list.
 *
 * Return: Number of characters printed.
 */

int _print_x(va_list args)
{

	unsigned int n = va_arg(args, unsigned int);
	char b[16];
	int i;

	hex_to_str(n, b, 0);

	for (i = 0; b[i]; i++)
	{

		write(1, &b[i], 1);
	}

	return (i);
}

/**
 * _print_X - Prints a hexadecimal number (uppercase).
 * @args: The arguments list.
 *
 * Return: Number of characters printed.
 */

int _print_X(va_list args)
{

	unsigned int n = va_arg(args, unsigned int);
	char b[16];
	int i;

	hex_to_str(n, b, 1);

	for (i = 0; b[i]; i++)
	{

		write(1, &b[i], 1);
	}

	return (i);
}
