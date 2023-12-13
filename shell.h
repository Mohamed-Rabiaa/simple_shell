#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 256
extern char **environ;

/*our header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>

/*helpful strings tools*/
size_t _strlen(char *s);
size_t strarr_len(char **strarr);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int remove_newline(char *str);
int check_spaces(char *line);
char **_strtok(char *str, char delim);
int _strcmpold(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
int _str123(char *string);
int _atoi(char *s);
/*main functions*/
void prompt(char *dir);
char *scanline(char *prog, int nonactive, int *linenum);
int execute_command(char **arguments, char *prog, int linenum);
char *search_command(char *command, char *prog);
ssize_t _getline(int fd, char **lineptr, size_t *n);
int _chdir(char *path, char *prog);
/*builtin functions*/
int precheck(char **arguments, char *prog, int linenum);
void f_exit(char **arguments, char *prog, int linenum);
int _setenv(char *name, char *value, int overwrite, char *prog);
int _unsetenv(char *name, char *prog);
void _printenv(void);
/*other functions*/
void free_arguments(char **arguments);
void *_realloc(void *ptr, unsigned int new_size);
/*print functions*/
int print_number(int n);
int _putchar(char c);
int _puts(char *str);
int errfun(char *prog, char **arguments, int linenum);

#endif /* SHELL_H */

