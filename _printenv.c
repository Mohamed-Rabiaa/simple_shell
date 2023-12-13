#include "shell.h"

/**
 *_printenv - prints all the environment variables
 */
void _printenv(void)
{
	char **temp = environ;

	while (*temp)
	{
		write(STDOUT_FILENO, *temp, _strlen(*temp));
		write(STDOUT_FILENO, "\n", 1);

		temp++;
	}
}

