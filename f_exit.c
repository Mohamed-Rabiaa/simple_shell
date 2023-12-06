#include "shell.h"

/**
 * f_exit - exits the program
 * @arguments: our arguments
 * Return: no return
 */
void f_exit(char **arguments)
{
	free_arguments(arguments);
	exit(EXIT_SUCCESS);
}
