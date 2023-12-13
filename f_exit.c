#include "shell.h"

/**
 * f_exit - exits the program
 * @arguments: our arguments
 * Return: no return
 */
void f_exit(char **arguments)
{
	int eistat = 0;

	if (arguments[1])
	{
		eistat = _atoi(arguments[1]);
		/*this function starts if arguments = exit*/
		free_arguments(arguments);
		exit(eistat);
	}
	else
	{
		free_arguments(arguments);
		exit(errno);
	}
}

