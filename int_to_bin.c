#include "main.h"

/**
 * unsigned_int_to_binary - Converts the unsigned int value
 * to binary string.
 * @n: The unsigned integer to be converted.
 * @buf: Pointer to the buffer_t struct.
 *
 * Return: Number of characters written to the buffer or -1 if error.
 */

int unsigned_int_to_binary(unsigned int n, buffer_t *buf)
{

	int count = 0;

	if (n == 0)
	{
		if (add_to_buffer(buf, '0') == -1)
		{
			return (-1);
		}
		return (1);
	}

	unsigned int highest_bit_pos = 1u << (sizeof(n) * 8 - 1);

	while (!(n & highest_bit_pos))
	{

		highest_bit_pos >>= 1;
	}

	while (highest_bit_pos)
	{

		char bit = (n & highest_bit_pos) ? '1' : '0';

		if (add_to_buffer(buf, bit) == -1)
		{
			return (-1);
		}
		count++;
		highest_bit_pos >>= 1;
	}

	return (count);
}
