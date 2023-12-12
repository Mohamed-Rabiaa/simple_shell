#include "shell.h"
/**
 *_chdir - Changes the current directory of the process
 *@path: the directory to change to
 *@prog: the name of the program
 *
 *Return: 0 on success
 *-1 on failure
*/
int _chdir(char *path, char *prog)
{
	char *dir = NULL;

	char buffer[BUFF_SIZE];

	if (!path || _strcmp(path, "$HOME") == 0)
	{
		dir = "/root";
	}
	else if (_strcmp(path, "-") == 0)
	{
		dir = getenv("OLDPWD");
		write(STDOUT_FILENO, dir, _strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
		_setenv("OLDPWD", getcwd(buffer, BUFF_SIZE), 1, prog);
	}
	else
	{
		dir = path;
	}
	if (chdir(dir) == -1)
	{
		perror(prog);
		return (-1);
	}
	_setenv("PWD", dir, 1, prog);
	return (0);
}
