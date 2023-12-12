#include "shell.h"
/**
 *_getline - reads an entire line from a stream and stores it in a buffer.
 *@fd: a file descriptor
 *@lineptr: the buffer to store the line in
 *@n: the number of characters to read
 *Return: the number of characters read or -1 on error or end of file.
 */

ssize_t _getline(int fd, char **lineptr, size_t *n)
{
	size_t len = 0;
	char c, *temp;
	ssize_t r;

	if (fd < 0 || lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFF_SIZE);
		if (*lineptr == NULL)
			return (-1);
		*n = BUFF_SIZE;
	}
	while ((r = read(fd, &c, 1)) > 0)
	{
		(*lineptr)[len++] = c;
		if (len == *n)
		{
			temp = _realloc(*lineptr, *n + BUFF_SIZE);
			if (temp == NULL)
				return (-1);
			*lineptr = temp;
			*n += BUFF_SIZE;
		}
		if (c == '\n')
			break;
	}
	if (r == 0)
	{
		if (len == 0)
			return (0);
		else
			return (len);
	}
	else if (r == -1)
		return (-1);
	(*lineptr)[len] = '\0';
	return (len);
}

