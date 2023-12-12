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
		if (!(_strcmpold(arguments[0], exitword)))
		{
			f_exit(arguments);
		}
		else if (_strcmpold(arguments[0], "setenv") == 0)
		{
			_setenv(arguments[1], arguments[2], 1, prog);
			free_arguments(arguments);
			return (0);
		}
		else if (_strcmpold(arguments[0], "unsetenv") == 0)
		{
			_unsetenv(arguments[1], prog);
			free_arguments(arguments);
			return (0);
		}
	}

	return (-1);
}

