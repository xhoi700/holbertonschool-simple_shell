#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Environment utilities */
int _printenv(void);
char *_getenv(char *var);

/* Command path */
char *command_path(char *cmd);
int command_read(char *s);
int execute(char *cmd_arr[]);

void trim_whitespace(char *str);

#endif
