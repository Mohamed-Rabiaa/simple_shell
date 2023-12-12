#include "shell.h"
/**
 * main - simple shell
 * @argc: argument count
 * @argv: the arguments
 * Return: 0 when success
 */
int main(int argc, char *argv[])
{
	char **arguments, *command, *dir, *prog;
	char buffer[BUFF_SIZE];
	int active = 1, nonactive = 0;

	prog = argv[0];
	(void)argc;
	if (!isatty(STDIN_FILENO))
		nonactive = 1;
	while (active)
	{
		if (!nonactive)
		{
			dir = getcwd(buffer, BUFF_SIZE);
			prompt(dir);
		}
		command = scanline(prog);
		if (command && command[0] != '\0')
		{
			arguments = _strtok(command, ' ');
			free(command);
			execute_command(arguments, prog);
		}

		if (nonactive)
			active = 0;
	}
	/*printf("%s\n\n", search_command("ls"));*/
	return (0);
}

