#ifndef MAIN__H
#define MAIN__H


#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char **_get_token(char *input);
void free_memory(char **args, char *path);
int exec_cmd(char *input);
char *_get_env(char *input);
char *purge_whiteSpace(char *input);


#endif
