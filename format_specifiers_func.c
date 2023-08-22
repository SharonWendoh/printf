#include "main.h"

/**
 * _print_ch - Prints a character.
 * @args: The arguments list.
 *
 * Return: Number of characters printed.
 */

int _print_ch(va_list args)
{

	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * _print_str - Prints a string.
 * @args: The arguments list.
 *
 * Return: Number of characters printed.
 */

int _print_str(va_list args)
{

	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	for (; *str; str++, count++)
	{
		write(1, str, 1);
	}

	return (count);
}
/**
 * _print_pct - Prints the percent symbol.
 * @args: The argument list. Not used in this function.
 *
 * Return: NUmber of characters printed.
 */

int _print_pct(va_list args)
{
	char c = '%';

	(void)args; /* Indicate that args is intentionally not used. */

	write(1, &c, 1);

	return (1);
}
/**
 * _print_int - Prints the integer value.
 * @args: The arguments list.
 *
 * Return: The number of characters printed.
 */

int _print_int(va_list args)
{
	int n = va_arg(args, int);
	char b[21];
	int i;

	int_to_str(n, b);

	for (i = 0; b[i]; i++)
	{
	write(1, &b[i], 1);
	}

	return (i);
}
