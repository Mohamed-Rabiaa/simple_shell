#include "shell.h"
/**
 * prompt - display prompt to stdout
 *
 * Return: no return
 */
void prompt(void)
{
	char *message = "$ ";

	write(STDOUT_FILENO, message, _strlen(message));
}
