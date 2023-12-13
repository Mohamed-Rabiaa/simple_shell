#include "shell.h"

/**
 * precheck - check for built in commands
 * @arguments: our arguments
 * @prog: our prog name
 * Return: 0 on success, -1 if fail
 */
int precheck(char **arguments, char *prog)
{
	char *exitword = "exit";

	if (arguments)
	{
		if (!(_strcmp(arguments[0], exitword)))
		{
			f_exit(arguments);
		}
		else if (_strcmp(arguments[0], "setenv") == 0)
		{
			/*_setenv(arguments[1], arguments[2], 1, prog);*/
			setenv(arguments[1], arguments[2], 1);
			free_arguments(arguments);
			return (0);
		}
		else if (_strcmp(arguments[0], "unsetenv") == 0)
		{
			/*_unsetenv(arguments[1], prog);*/
			unsetenv(arguments[1]);
			free_arguments(arguments);
			return (0);
		}
		else if (strcmp(arguments[0], "cd") == 0)
		{
			_chdir(arguments[1], prog);
			return (0);
		}
	}

	return (-1);
}
