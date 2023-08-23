#include "main.h"

/**
 * uint_to_str - Converts unsigned int to string.
 * @n: Unsinged int value to be converted.
 * @b: Buffer to hold string.
 *
 * Return: Pointer to the string.
 */

char *uint_to_str(unsigned int n, char *b)
{

	char *ptr = b + 20;
	*ptr = '\0';

	do {

		*--ptr = '0' + (n % 10);
		n /= 10;
	} while (n > 0);

	return (ptr);
}
/**
 * octal_to_str - Converts octal int to string
 * @n: Unsinged int value to be converted.
 * @b: Buffer to hold string.
 *
 * Return: Pointer to the string.
 */

char *octal_to_str(unsigned int n, char *b)
{

	char *ptr = b + 65;
	*ptr = '\0';

	do {

		*--ptr = '0' + (n % 8);
		n /= 8;
	} while (n > 0);

	return (ptr);
}
/**
 * hex_to_str - Converts hexadecimal int to string.
 * @n: Unsinged int value to be converted.
 * @b: Buffer to hold string.
 * @uppercase: Parameter to use for ternary operation
 *
 * Return: Pointer to the string.
 */

char *hex_to_str(unsigned int n, char *b, int uppercase)
{

	char *ptr = b + 8;
	char chars[] = "0123456789abcdef";
	char CHARS[] = "0123456789ABCDEF";

	*ptr = '\0';

	do {

		*--ptr = uppercase ? CHARS[n % 16] : chars[n % 16];
		n /= 16;
	} while (n > 0);

	return (ptr);


}
