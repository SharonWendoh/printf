#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces an output according to a format
 *
 * @format: format to be followed
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int length = 0;
	va_list list;
	char *string;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(list, int));
					length++;
					break;
				case 's':
					for (string = va_arg(list, char *); *string; string++)
					{
						_putchar(*string);
						length++;
					}
					break;
				case '%':
					_putchar(va_arg(list, int));
					length++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			length++;
		}
		format++;
	}
	va_end(list);
	return (length);
}
