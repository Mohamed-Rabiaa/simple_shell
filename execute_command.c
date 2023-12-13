#include "shell.h"
/**
 * execute_command - check if command exist and execute it
 * @arguments: the arguments given by the user
 * @prog: our program name
 * @linenum: line number
 * Return: 0 if success, -1 on failure
 */
int execute_command(char **arguments, char *prog, int linenum)
{
	char *full_cmd = NULL;
	struct stat st;
	pid_t childpid;
	int status;

	if (arguments == NULL)
		return (-1);
	if (precheck(arguments, prog, linenum) == 0)
		return (0);
	errno = 0;
	if (arguments[0])
	{ /*check if the command is full*/
		if (_strchr(arguments[0], '/'))
			full_cmd = arguments[0];
		else
			full_cmd = search_command(arguments[0], prog);
	} /*check if the command is executable*/
	if (stat(full_cmd, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		childpid = fork();
		if (childpid == -1)
		{
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
		{
			wait(&status);
			errno = status;
		}
	}
	else
		errfun(prog, arguments, linenum);
	return (0);
}

