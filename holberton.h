#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

void child_process(char *str, char **args, char **env);
int lenMalloc(char *pointer);
char *_getenv(char *nameVar, char **env);
char *check_paths(char **args, char **env);
#endif
