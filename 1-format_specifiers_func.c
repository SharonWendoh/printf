#include "main.h"

/**
 * _print_binary - Prints the binary value.
 * @args: The arguments list.
 *
 * Return: The number of characters to be printed.
 */

int _print_binary(va_list args)
{

	unsigned int value = va_arg(args, unsigned int);
	char *binary_representation = unsigned_int_to_binary(value);
	int len;

	if (!binary_representation)
		return (-1);

	len = write(1, binary_representation, strlen(binary_representation));
	free(binary_representation);

	return (len);
}
