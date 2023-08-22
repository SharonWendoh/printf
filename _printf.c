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
	va_list args;
	int i = 0, count = 0, (*function_to_call)(va_list);

	va_start(args, format);
	for (; format && format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'c' ||
		format[i + 1] == 's' || format[i + 1] == '%' ||
		format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			format++;
			if (*format == '%')
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
				case 'd':
				case 'i':
					count += _printf_int(va_arg(args, int));
					i++;
					continue;

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