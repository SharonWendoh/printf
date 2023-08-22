#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces an output according to a format
 *
 * @format: format to be followed
 *
 * Return: the number of characters printed
 */
int _printf(char *format, ...)
{
	int length = 0;
	va_list list;
	int (*handler)(va_list);

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				length++;
			}
			else
			{
			handler = get_specifier(format);

			if (handler != NULL)
			{
				length += handler(list);
				format++;
			}
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