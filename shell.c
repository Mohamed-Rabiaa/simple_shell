#include "shell.h"
/**
 * main - simple shell
 * 
 * Return: 0 when success
 */
int main(void)
{
	char *command;
	/*char **environ;*/

	while(1)
	{
		prompt();
		command = scanline();
	}
	(void)command;

	return (0);
}
