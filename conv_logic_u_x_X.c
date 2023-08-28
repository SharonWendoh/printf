#include "main.h"

/**
 * uint_to_str - Converts unsigned int to string.
 * @n: Unsinged int value to be converted.
 * @buf:Pinter to the buffer_t struct.
 *
 * Return: Number of characters written or -1 if error.
 */

int uint_to_str(unsigned int n, buffer_t *buf)
{

	int count = 0, i;
	char digits[11];

	if (n == 0)
	{
		(add_to_buffer(buf, '0'));
		return (1);
	}

	while (n > 0)
	{
		digits[count++] = '0' + (n % 10);
		n /= 10;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (add_to_buffer(buf, digits[i]) == -1)
			return (-1);
	}

	return (count);
}
/**
 * octal_to_str - Converts octal int to string
 * @n: Unsinged int value to be converted.
 * @buf:Pinter to the buffer_t struct.
 *
 * Return: Number of characters written or -1 if error.
 */

int octal_to_str(unsigned int n, buffer_t *buf)
{

	int count = 0, i;
	char digits[12];

	if (n == 0)
	{
		return (add_to_buffer(buf, '0'));
	}

	while (n > 0)
	{
		digits[count++] = '0' + (n % 8);
		n /= 8;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (add_to_buffer(buf, digits[i]) == -1)
			return (-1);
	}

	return (count);
}
/**
 * hex_to_str - Converts hexadecimal int to string.
 * @n: Unsinged int value to be converted.
 * @buf:Pinter to the buffer_t struct.
 * @uppercase: Parameter to use for ternary operation
 *
 * Return: Number of characters written or -1 if error.
 */

int hex_to_str(unsigned int n, buffer_t *buf, int uppercase)
{

	int count = 0, i;
	char chars[] = "0123456789abcdef";
	char CHARS[] = "0123456789ABCDEF";
	char digits[9];

	while (n > 0)
	{
		digits[count++] = uppercase ? CHARS[n % 16] : chars[n % 16];
		n /= 16;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (add_to_buffer(buf, digits[i]) == -1)
			return (-1);
	}

	return (count);
}
