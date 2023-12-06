#include "shell.h"
/**
 * execute_command - check if command exist and execute it
 * @command: the command given by the user
 * Return: 0 if success, -1 on failure
 */
int execute_command(char *command, char *prog)
{
	char **arguments;
	char *full_cmd = NULL;
	struct stat st;
	pid_t childpid;
	int status;

	if (command == NULL)
		return (-1);
	arguments = _strtok(command, ' ');
	if (command)
		free(command);

	if (arguments[0])
	{
                /*check if the command is full*/
		if (_strchr(arguments[0], '/'))
			full_cmd = arguments[0];
		else
			full_cmd = search_command(arguments[0]);
	}
	 /*check if the command is executable*/
	if (stat(full_cmd, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		childpid = fork();
		if (childpid == -1)
		{
			free_arguments(arguments);
			perror(prog);
			exit(EXIT_FAILURE);
		}
		else if (childpid == 0)
		{
			execve(full_cmd, arguments, environ);
			perror(prog);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	else
	{
		perror(prog);
		exit(EXIT_FAILURE);
	}
	free_arguments(arguments);
	return (0);
}
