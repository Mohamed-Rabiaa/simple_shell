#include "shell.h"
/**
 * main - simple shell
 *
 * Return: 0 when success
 */
int main(int argc, char *argv[])
{
	char *command, *prog;
	int active = 1, nonactive = 0;

	prog = argv[0];
	(void)argc;
	if (!isatty(STDIN_FILENO))
		nonactive = 1;
	while (active)
	{
		if (!nonactive)
			prompt();
		command = scanline(prog);
		execute_command(command, prog);
		if (nonactive)
			active = 0;
	}

	return (0);
}

