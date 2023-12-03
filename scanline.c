#define _GNU_SOURCE
#include "shell.h"
/**
 * scanline - scans the command given by user
 * 
 * Return: the command
 */
char *scanline(void)
{
	char *line = NULL, *command = "scan";
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	/*if (read == 1 && line[0] == '\n')
	{
		write(STDOUT_FILENO, line, _strlen(line));
		exit(EXIT_SUCCESS);
	}
	else */if (read == -1)
	{
		perror("getline");
		free(line);
		exit(EXIT_FAILURE);
	}
	remove_newline(line);
	command = _strdup(line);
	free(line);
	return (command);
}
