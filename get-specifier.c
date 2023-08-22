#include "main.h"
/**
 * get_specifier - Selects the correct function to perform
 * when a specifier is chosen
 *
 * @format - the format specifier
 *
 * Return: poniter to the function that corresponds to the chosen specifier
 */
int (*get_specifier(char *format))(va_list)
{
	format_specifier x[] = {
		{"c", c},
		{"s", s},
		{NULL, NULL}
	};
	int i;

	for (i = 0; x[i].s != NULL; i++)
	{
		if (*(x[i].s) == *format)
		{
			return (x[i].function);
			break;
		}
	}
	return (NULL);
}
