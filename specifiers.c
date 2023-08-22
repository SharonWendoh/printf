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
/**
 * print_number - Prints n integer
 *
 * @n: integer to be printed
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int length = 0;

	if (n < 0)
	{
		_putchar('-');
		length++;
		n =  -n;
	}
	if (n / 10)
	{
		length += print_number(n / 10);
	}
	_putchar((n % 10) + '0');
	length++;
	return (length);
}
/**
 * d_i - Print signed integer
 *
 * @d: Integer to be printed
 *
 * Return: Number of characters to be printed
 */
int d_i(va_list d)
{
	int num = va_arg(d, int);
	int length = 0;

	length += print_number(num);
	return (length);
}
