#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src
 * @output: A buffer_t struct.
 * @src: pointer to the memory area to copy.
 * @n: bytes
 * Return: The number of bytes copied.
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(output->buffer) = *(src + i);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;
	}

	return (n);
}

/**
 * free_buffer - Frees a buffer struct.
 * @output: The buffer_t struct to be freed.
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * init_buffer - Initializes a variable of struct type buffer_t.
 *
 * Return: A pointer to the initialized buffer_t.
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(*output));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
