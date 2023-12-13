#include "shell.h"

/**
 *fill_str - fills str with the name and value
 *@name: a name
 *@value: a value
 *@prog: the program name
 *Return: the str filled
 */
char *fill_str(char *name, char *value, char *prog)
{
	char *str = NULL;

	str = malloc(_strlen(name) + _strlen(value) + 2);
	if (!str)
	{
		errno = ENOMEM;
		perror(prog);
		return (NULL);
	}
	str[0] = '\0';
	_strcat(str, name);
	_strcat(str, "=");
	_strcat(str, value);

	return (str);
}
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
				environ[i] = fill_str(name, value, prog);
				if (environ[i] == NULL)
					return (-1);
				return (0);
			}
			return (0);
		}
		i++;
	}
	if (environ[i - 1] == NULL)
	{
		environ[i - 1] = fill_str(name, value, prog);
		if (environ[i - 1] == NULL)
			return (-1);
		environ[i] = NULL;
		return (0);
	}
		environ[i] = fill_str(name, value, prog);
		if (environ[i] == NULL)
			return (-1);
	environ[i + 1] = NULL;
	return (0);
}
