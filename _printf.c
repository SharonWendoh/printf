#include "main.h"

/**
 * _printf - our custom printf function.
 * @format: our format string.
 *
 * Return: Number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, (*function_to_call)(va_list);

	va_start(args, format);
	for (; format && format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'c' ||
		format[i + 1] == 's' || format[i + 1] == '%'))
		{

			switch (format[i + 1]) /* call functions */
			{
				case 'c':
					function_to_call = _print_ch;
					break;
				case 's':
					function_to_call = _print_str;
					break;
				case '%':
					function_to_call = _print_pct;
					break;
			}
			count += function_to_call(args);
			i++;
		}
		else
		{

			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}

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
 * @args: The argument list.
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
