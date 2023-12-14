#include "shell.h"

/**
 * _str123 - checks for any character that isn't a number
 * @string: our string
 * Return: 0 if all are numbers, 1 otherwise
 */
int _str123(char *string)
{
	int i;

	while (string[i] != '\0')
	{
		if (string[i] > '9' || string[i] < '0')
			return (1);
		i++;
	}
	return (0);
}
/**
 * f_exit - exits the program
 * @arguments: our arguments
 * @linenum: number of the line
 * @prog: our program name
 * Return: no return
 */
void f_exit(char **arguments, char *prog, int linenum)
{
	int eistat = 0, tmp = 0;

	(void)prog;
	(void)linenum;
	if (arguments[1])
	{
		/*this function starts if arguments = exit*/
		eistat = _atoi(arguments[1]);
		free_arguments(arguments);
		exit(eistat);
	}
	else
	{
		free_arguments(arguments);
		if (errno >= 256)
		{
			tmp = errno % 256;
			errno /= 256;
			errno += tmp;
		}
		exit(errno);
	}
}

