#include "shell.h"

/**
 * execute_command - check if command exist and execute it
 * @command: the command given by the user
 * Return: 0 if success, -1 on failure
 */
int execute_command(char *command)
{
	char *cmd;
	char **arguments;
	pid_t childpid;

	cmd = _strdup(command);
	if (cmd == NULL)
		return (-1);
	arguments = _strtok(cmd);
	childpid = fork();
	if (childpid == -1)
	{
		free(cmd);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (childpid == 0)
	{
	execve(arguments[0], arguments, NULL);
	perror("execve");
	return (-1);
	}
	else
	{
		wait(&childpid);
	}
	return (0);
}

