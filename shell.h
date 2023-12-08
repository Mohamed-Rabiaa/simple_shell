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
int _strlen(char *s);
char *_strdup(char *str);
int remove_newline(char *str);
char **_strtok(char *str, char delim);
int _strcmpold(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _atoi(char *s);
/*main functions*/
void prompt(void);
char *scanline(char *prog);
int execute_command(char *command, char *prog);
char *search_command(char *command, char *prog);
ssize_t _getline(int fd, char **lineptr, size_t *n);

/*builtin functions*/
void precheck(char **arguments);
void f_exit(char **arguments);
/*other functions*/
void free_arguments(char **arguments);
void *_realloc(void *ptr, unsigned int new_size);




#endif /* SHELL_H */
