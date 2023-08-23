#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
*print_rev - prints astring in reverse
*@r: string to print
*@f: Pointer to flags.
*
*Return: number of chars printed
*/
int print_rev(va_list r, flags_t *f)
{
	(void)f; /* Intentionally not used */
	char *st;
	int i, j = 0;

	st = va_arg(r, char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
