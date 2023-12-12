#include "shell.h"
/**
 * prompt - display prompt to stdout
 *@dir: a directory
 * Return: no return
 */
void prompt(char *dir)
{
	char *message = "$ ";

	if (dir)
	{
		write(STDOUT_FILENO, dir, _strlen(dir));
	}

	write(STDOUT_FILENO, message, _strlen(message));
}
