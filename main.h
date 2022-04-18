#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct built_in
{
    char *name;
    int (*function)(char**);
} command_t;

void execute(char **tokens);
char *PATH(char *comm);
pid_t fork(void);
char **_strtok(char **tokens, char *str, char *delim);
int exit2(char **tokens);
#define UNUSED(x) (void)(x);

#endif
