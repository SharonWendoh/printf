#include "main.h"

/**
 * _print_ch - Prints a character.
 * @args: The arguments list.
 * @buf: Pointer to a buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_ch(va_list args, buffer_t *buf)
{

	char c = va_arg(args, int);

	add_to_buffer(buf, c);
	return (1);
}

/**
 * _print_str - Prints a string.
 * @args: The arguments list.
 * @buf: Pointer to a buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_str(va_list args, buffer_t *buf)
{

	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	for (; *str; str++, count++)
	{
		add_to_buffer(buf, *str);
	}

	return (count);
}
/**
 * _print_pct - Prints the percent symbol.
 * @args: The argument list. Not used in this function.
 * @buf: Pointer to a buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_pct(va_list args, buffer_t *buf)
{
	char c = '%';

	(void)args; /* Indicate that args is intentionally not used. */

	add_to_buffer(buf, c);

	return (1);
}
/**
 * _print_int - Prints the integer value.
 * @args: The arguments list.
 * @buf: Pointer to a buffer_t struct.
 *
 * Return: The number of characters printed.
 */

int _print_int(va_list args, buffer_t *buf)
{
	int n = va_arg(args, int);

	return (int_to_str(n, buf));
}

/**
 * _print_u - Prints an unsigned integer.
 * @args: The arguments list.
 * @buf: Pointer to a buffer_t struct.
 *
 * Return: The number of characters printed.
 */

int _print_u(va_list args, buffer_t *buf)
{
	unsigned int n = va_arg(args, unsigned int);

	return (uint_to_str(n, buf));
}
