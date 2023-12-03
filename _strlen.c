#include "shell.h"
/**
 * _strlen - a function that returns the length of a string
 * @s: pointer to our char
 * Return: length of a string
 */
int _strlen(char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
		a++;

	return (a);
}
