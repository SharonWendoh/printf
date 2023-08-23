#include "main.h"

/**
 * init_format_handlers - Initialize the array of format handlers.
 * @format_mappers: Array to fill with format handlers.
 */

void init_format_handlers(format_mapper_t *format_mappers)
{
	format_mappers[0].specifier = 'c';
	format_mappers[0].handler = _print_ch;

	format_mappers[1].specifier = 's';
	format_mappers[1].handler = _print_str;

	format_mappers[2].specifier = '%';
	format_mappers[2].handler = _print_pct;

	format_mappers[3].specifier = 'i';
	format_mappers[3].handler = _print_int;

	format_mappers[4].specifier = 'd';
	format_mappers[4].handler = _print_int;

	format_mappers[5].specifier = 'b';
	format_mappers[5].handler = _print_binary;

	format_mappers[6].specifier = 'u';
	format_mappers[6].handler = _print_u;

	format_mappers[7].specifier = 'o';
	format_mappers[7].handler = _print_o;

	format_mappers[8].specifier = 'x';
	format_mappers[8].handler = _print_x;

	format_mappers[9].specifier = 'X';
	format_mappers[9].handler = _print_X;

	format_mappers[10].specifier = '\0';
	format_mappers[10].handler = NULL;
}

/**
 * handle_format - Handles the format specifiers and buffer characters.
 * @format: The format string.
 * @i: Pointer to the index in the format string.
 * @args: List of arguments.
 * @buffer: The buffer to store characters.
 * @printed_chars: Pointer to the current count of characters printed.
 * @format_mappers: Array of format handlers.
 */

void handle_format(const char *format, int *i, va_list args, buffer_t *buffer,
		int *printed_chars, format_mapper_t *format_mappers)
{
	format_function function_to_call;

	function_to_call = fetch_handler(format_mappers, format[*i + 1]);
	if (function_to_call)
	{

		*printed_chars += function_to_call(args, buffer);
		(*i)++;
	}
	else
	{

		add_to_buffer(buffer, format[*i]);
	}
}

/**
 * _printf - our custom printf function.
 * @format: our format string.
 *
 * Return: Number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	if (!format)
		return (-1);

	buffer_t buffer = {{0}, 0};
	int i = 0;
	int printed_chars = 0; /* total number of characters to be printed */

	format_mapper_t format_mappers[11];

	va_list args;

	va_start(args, format);

	init_format_handlers(format_mappers);

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			handle_format(format, &i, args, &buffer,
				      &printed_chars, format_mappers);
		}
		else
		{
			add_to_buffer(&buffer, format[i]);
				      printed_chars++;
		}
	}

	if (buffer.index > 0)
	{
		write(1, buffer.buffer, buffer.index);
	}

	va_end(args);

	return (printed_chars);
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
