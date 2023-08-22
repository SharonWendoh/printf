#include "main.h"

/**
 * init_format_handlers - Initialize the array of format handlers.
 * @format_mappers: Array to fill with format handlers.
 */

void init_format_handlers(format_mapper_t *format_mappers)
{
	format_mappers[0].specifier ='c';
	format_mappers[0].handler = _print_ch;

	format_mappers[1].specifier ='s';
	format_mappers[1].handler = _print_str;

	format_mappers[2].specifier ='%';
	format_mappers[2].handler = _print_pct;

	format_mappers[3].specifier ='i';
	format_mappers[3].handler = _print_int;

	format_mappers[4].specifier ='d';
	format_mappers[4].handler = _print_int;

	format_mappers[5].specifier ='\0';
	format_mappers[5].handler = NULL;
}

/**
 * _printf - our custom printf function.
 * @format: our format string.
 *
 * Return: Number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	format_function function_to_call;
	format_mapper_t format_mappers[6];

	init_format_handlers(format_mappers);

	va_start(args, format);
	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			function_to_call =
				fetch_handler(format_mappers, format[i + 1]);
			if (function_to_call)
			{

				count += function_to_call(args);
				i++;
			}
			else
			{
				write(1, &format[i], 1);
				count++;
			}
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
 * fetch_handler - function that fetches the appropriate handler functiion
 * for a given specifier.
 * @format_mappers: Array of format handlers.
 * @specifier: format specifier character.
 *
 * Return: NULL, or pointer to the appropriate function if NULL is not found.
 */

format_function fetch_handler(format_mapper_t *format_mappers, char specifier)
{

	int i;

	for (i = 0; format_mappers[i].specifier; i++)
	{
		if (format_mappers[i].specifier == specifier)
		{
			if (!format_mappers[i].handler)
			{

				return (NULL);
			}
			return (format_mappers[i].handler);
		}
	}

	return (NULL);

}
