#include "shell.h"

/**
 * precheck - check for built in commands
 * @arguments: our arguments
 * Return: no return
 */
void precheck(char **arguments)
{
	char *exitword = "exit";

	if (arguments)
	{
		if (!(_strcmpold(arguments[0], exitword)))
		{
			f_exit(arguments);
		}
	}
}
