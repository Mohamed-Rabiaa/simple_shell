#define _GNU_SOURCE
#include "shell.h"

/*
 * char *line = NULL, *command = NULL;
 * void handle_sigint(int sig)
 * {
 *	free(line);
 *	free(command);
 *	exit(EXIT_FAILURE);
 *	}
 */

/**
 * scanline - scans the command given by user
 * @prog: our program name
 * Return: the command
 */
char *scanline(char *prog, int nonactive)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/*signal(SIGINT, handle_sigint(2));*/
	errno = 0;
	/*read = getline(STDIN_FILENO, &line, &len);*/
	read = getline(&line, &len, stdin);
	/*
	 *if (read == 1 && line[0] == '\n')
	 *{
	 *	write(STDOUT_FILENO, line, _strlen(line));
	 *	exit(EXIT_SUCCESS);
	 *}
	 *else
	 */
	if (read == -1)
	{
		if (nonactive)
		{
			free(line);
			return ("end has been !found!");
		}
		free(line);
		perror(prog);
		exit(EXIT_FAILURE);
	}
	remove_newline(line);

	return (line);
}


