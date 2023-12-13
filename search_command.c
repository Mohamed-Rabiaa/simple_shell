#include "shell.h"
/**
 *search_command - searches for a command in the directories
 *saved in PATH
 *@command: the command to search for
 *@prog: The name of the program
 *Return: the directory of the command/file
 */
char *search_command(char *command, char *prog)
{
	char **dirs;
	char *path;
	DIR *d;
	struct dirent *dirent;

	if (!command)
		return (NULL); /*seperate the directories saved in PATH*/
	path = getenv("PATH"); /*and save them in dirs*/
	if (path)
		dirs = _strtok(path, ':');
	if (dirs)
	{
		while (*dirs)
		{
			d = opendir(*dirs);
			if (!d)
			{
				perror(prog);
				return (NULL);
			}
			else
			{
				while ((dirent = readdir(d)) != NULL)
				{
					if (strcmp(dirent->d_name, command) == 0)
					{
						closedir(d);
						_strcat(*dirs, "/");
						return (_strcat(*dirs, command));
					}
				}
			}
			if (*dirs)
				free(*dirs);
			dirs++;
		}
	}
	return (NULL);
}


