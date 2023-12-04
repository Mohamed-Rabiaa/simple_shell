#include "shell.h"

/**
 * *_strdup - returns a pointer to a newly allocated space in memory
 * @str: The string to copy
 * Return: pointer to string, or NULL if it fails
 */
char *_strdup(char *str)
{
	int i = 0;
	char *a;

	if (str == NULL)
	{
		return (NULL);
	}
	i = _strlen(str);

	a = malloc(i + 1);
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		a[i] = str[i];
	}
	a[i] = '\0';

	return (a);
}
