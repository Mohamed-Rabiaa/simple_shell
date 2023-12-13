#include "shell.h"

/**
 * print_number - prints a number
 * @n: our int
 * Return: numbers of characters printed
 */
int print_number(int n)
{
	unsigned int a, b, c, d = 0;

	if (n < 0)
	{
		a = -1 * n;
		_putchar('-');
		d++;
	}
	else
	{
		a = n;
	}
	b = a;
	c = 1;
	while (b > 9)
	{
		b = b / 10;
		c = c * 10;
	}
	while (c >= 1)
	{
		_putchar(((a / c) % 10) + '0');
		c = c / 10;
		d++;
	}
	return (d);
}
/**
 * _putchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
/**
 * _puts - a function that prints a string to stderr
 * @str: pointer to our char
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int a = 0;

	while (*(str + a) != '\0')
	{
		_putchar(str[a]);
		a++;
	}
	return (a);
}
/**
 * errfun - prints error msg not found
 * @prog: our program name
 * @arguments: our arguments
 * @linenum: line number
 * Return: number of characters printed
 */
int errfun(char *prog, char **arguments, int linenum)
{
	int i = 0;

	i += _puts(prog);
	i += _puts(": ");
	i += print_number(linenum);
	i += _puts(": ");
	i += _puts(arguments[0]);
	i += _puts(": not found\n");
	errno = 127;
	return (i);
}
