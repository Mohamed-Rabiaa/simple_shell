#include "shell.h"

/**
 * _strcmpold - compares two strings
 * @s1: our pointer to char
 * @s2: our pointer to char
 * Return: pointer to the resulting string dest
 */
int _strcmpold(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
