#include "shell.h"

/**
 * free_arguments -  returns a pointer to a 2 dimensional array of integers
 * @arguments: what to be freed
 * Return: no return
 */

void free_arguments(char **arguments)
{
	int i;

	if (arguments)
	{
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);

		free(arguments);
	}
}
