#include "shell.h"

/**
 * _atoi - converts a string to an integer.
 * @s: pointer to our char
 * Return: the number
 */
int _atoi(char *s)
{
	unsigned int b;
	int a = 1; /*for the sign*/
	int c = 0; /*in case there are no numbers*/
	unsigned int d = 0; /*will make the numbers x 10*/
	unsigned int e = 0; /*our final number*/

	for (b = 0; s[b] != '\0'; b++)
	{
		if (d > 0 && (s[b] > '9' || s[b] < '0'))
		{
			break;
		}
		if (s[b] == '-')
		{
			a = -a;
		}
		if (s[b] >= '0' && s[b] <= '9')
		{
			if (c == 1)
			{
				e = e + d;
				e = e * 10;
			}
			d = s[b] - 48;
			c = 1;
		}
	}
	e = e + d;

	return (e * a * c);
}
