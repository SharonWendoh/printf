#include "main.h"

/**
 * int_to_str - Converts integer to string.
 * @n: Integer to convert into string
 * @b: A buffer to hold the string representation of the integer.
 *
 * Return: A pointer to the string representation of the integer.
 */

char *int_to_str(int n, char *b)
{

	int i = 0;
	int is_negative = 0;

	if (n == 0)
	{

		b[i++] = '0';
		b[i] = '\0';

		return (b);
	}

	if (n == INT_MIN)
	{

		b[i++] = '8';
		n /= 10;
		n = -n;
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n != 0)
	{

		b[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
	{

		b[i++] = '-';
	}
	b[i] = '\0';

	return (strrev(b));
}

/**
 * strrev - Reverse the string.
 * @s: string to be reversed.
 *
 * Return: A pointer to the reversed string.
 */

char *strrev(char *s)
{

	int i = 0, j = strlen(s) - 1;
	char temp;

	while (i < j)
	{

		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}
