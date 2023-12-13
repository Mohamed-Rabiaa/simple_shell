#include "shell.h"
/**
 *check_spaces - checks if a line contains spaces only
 *@line: a string
 *
 *Return: 1 if the line contains spaces only
 *0 if the line contains other characters
 */
int check_spaces(char *line)
{
	int i;

	int n;

	for (i = 0; line[i] != '\0'; i++)
	{
		if ((line[i] == ' ') && (line[i + 1] == ' '))
			n = 1;

		else if ((line[i] == ' ') && (line[i + 1] != ' ')
			 && (line[i + 1] != '\0'))
			n = 0;
	}
	return (n);
}
