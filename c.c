#include "main.h"
/**
 * c - Prints a character
 * @c: character to print
 *
 * Return: size of character
 */
int c(va_list c)
{
	int length = 0;

	_putchar(va_arg(c, int));
	length++;
	return (length);
}
