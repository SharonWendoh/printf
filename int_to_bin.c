#include "main.h"

/**
 * unsigned_int_to_binary - Converts the unsigned int value
 * to binary string.
 * @n: The unsigned integer to be converted.
 *
 * Return: Pointer to the binary string or NULL if failure.
 */

char *unsigned_int_to_binary(unsigned int n)
{

	char *binary;
	int count = 0, i;
	unsigned int temp = n;

	while (temp)
	{

		count++;
		temp >>= 1;
	}

	if (count == 0)
	{

		binary = malloc(2);
		if (!binary)
			return (NULL);
		strcpy(binary, "0");
		return (binary);
	}

	binary = malloc(count + 1);
	if (!binary)
		return (NULL);

	binary[count] = '\0';

	for (i = count - 1; i >= 0; i--)
	{

		binary[i] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	return (binary);
}
