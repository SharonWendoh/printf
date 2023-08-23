#include "main.h"

/**
 * add_to_buffer - Adds a character to the buffer or flushes when full.
 * @buf: Pointer to a buffer_t struct.
 * @c: Character to add to the buffer.
 *
 * Return: Nothing.
 */

int add_to_buffer(buffer_t *buf, char c)
{

	if (!buf || buf->index >= BUFSIZE)
	{

		ssize_t written = write(1, buf->buffer, buf->index);

		buf->index = 0;

		if (written < 0)
		{
			return (-1);
		}
	}
	buf->buffer[buf->index++] = c;

	return (0);
}
