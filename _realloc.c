#include "shell.h"

/**
 * _realloc -  reallocates a memory block
 * @ptr: our pointer
 * @new_size: the new size
 * Return: pointer, or NULL if it fails
 */

void *_realloc(void *ptr, unsigned int new_size)
{
	if (ptr == NULL)
	{
		if (new_size != 0)
			ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);
	ptr = malloc(new_size);

return (ptr);
}
