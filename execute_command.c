#include "shell.h"

/**
 * execute_command - check if command exist and execute it
 * @command: the command given by the user
 * Return: 0 if success, -1 on failure
 */
int execute_command(char *command, char *prog)
{
	char **arguments;
	pid_t childpid;
	int status;

	if (command == NULL)
		return (-1);
	arguments = _strtok(command);
	if (command)
		free(command);
	precheck(arguments);
	childpid = fork();
	if (childpid == -1)
	{
		free_arguments(arguments);
		perror(prog);
		exit(EXIT_FAILURE);
	}
	else if (childpid == 0)
	{
		execve(arguments[0], arguments, environ);
		perror(prog);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	free_arguments(arguments);
	return (0);
}

