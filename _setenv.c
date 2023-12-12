#include "shell.h"
/**
 * _setenv - Initializes a new environment variable, or modify an existing one
 * @name: the name of the variable to initialize or modify
 * @value: the value given to name
 * @overwrite: an integer to determine to modify the variable or not
 * @prog: the name of the program
 * Return: 0 on success
 * -1 on failure
 */
int _setenv(char *name, char *value, int overwrite, char *prog)
{
	int i = 0;
	char *str = NULL;

	if (!name || !value)
	{
		errno = EINVAL;
		perror(prog);
		return (-1);
	}
	while (environ[i])
	{
		if (_strcmp(environ[i], name) == 0)
		{
			if (overwrite)
			{
				free(environ[i]);
				str = malloc(_strlen(name) + _strlen(value) + 2);
				if (!str)
				{
					errno = ENOMEM;
					perror(prog);
					return (-1);
				}
				_strcat(str, name);
				_strcat(str, "=");
				_strcat(str, value);
				environ[i] = str;
				return (0);
			}
			return (0);
		}
		i++;
	}
	str = malloc(_strlen(name) + _strlen(value) + 2);
	if (!str)
	{
		errno = ENOMEM;
		perror(prog);
		return (-1);
	}
	str[0] = '\0';
	_strcat(str, name);
	_strcat(str, "=");
	_strcat(str, value);
	if (environ[i - 1] == NULL)
	{
		environ[i - 1] = str;
		environ[i] = NULL;
		return (0);
	}
	environ[i] = str;
	environ[i + 1] = NULL;
	return (0);
}

