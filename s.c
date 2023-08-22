#include "main.h"
/**
 * s - Prints a string
 *
 * @s: String to print
 *
 * Return: length of string
 */
int s(va_list s)
{
	int length = 0;
	char *string;

	for (string = va_arg(s, char *); *string; string++)
		{
			_putchar(*string);
			length++;
		}
	return (length);
}
