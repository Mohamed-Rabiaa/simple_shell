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
	int active = 1, nonactive = 0, linenum = 0;

	errno = 0;
	prog = argv[0];
	(void)argc;
	if (!isatty(STDIN_FILENO))
	{
		nonactive = 1;
		errno = 0;
	}
	while (active)
	{
		if (!nonactive)
		{
			dir = getcwd(buffer, BUFF_SIZE);
			prompt(dir);
		}
		command = scanline(prog, nonactive, &linenum);
		if (_strcmpold(command, "end has been !found!") == 0)
			return (errno);
		/*if (check_spaces(command) == 1)*/
			/*return (0);*/
		if (command && command[0] != '\0')
		{
			arguments = _strtok(command, ' ');
			free(command);
			execute_command(arguments, prog, linenum);
			free_arguments(arguments);
		}
		/*if (nonactive)*/
			/*active = 0;*/
	}
	return (0);
}

