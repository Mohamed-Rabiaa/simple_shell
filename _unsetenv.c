#include "shell.h"
/**
 *_unsetenv - deletes the variable name from the environment
 *@name: the name of the variable to remove
 *@prog: the name of the program
 *Return: 0 on success
 *-1 on failure
 */
int _unsetenv(char *name, char *prog)
{
	int i = 0, j;

	if (!name)
	{
		errno = EINVAL;
		perror(prog);
		return (-1);
	}

	else
	{
		while (environ[i])
		{
			if (_strcmp(environ[i], name) == 0)
			{
				free(environ[i]);
				for (j = i; environ[j]; j++)
					environ[j] = environ[j + 1];
				environ[j] = NULL;
				return (0);
			}
			i++;
		}
	}
	return (0);
}
