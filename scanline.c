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
 * @nonactive: flag for non interactive mode
 * @linenum: number of the line
 * Return: the command
 */
char *scanline(char *prog, int nonactive, int *linenum)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/*signal(SIGINT, handle_sigint(2));*/
	/*errno = 0;*/
	/*read = getline(STDIN_FILENO, &line, &len);*/
	read = getline(&line, &len, stdin);
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
	*linenum = *linenum + 1;

	return (line);
}

