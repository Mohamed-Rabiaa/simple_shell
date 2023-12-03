#ifndef SHELL_H
#define SHELL_H

/*our header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
/*#include <sys/wait.h>*/
#include <errno.h>
#include <limits.h>

/*helpful strings tools*/
int _strlen(char *s);
char *_strdup(char *str);
int remove_newline(char *str);
/*main functions*/
void prompt(void);
char *scanline(void);



#endif /* SHELL_H */
