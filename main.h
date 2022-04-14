#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct args_s
{
	char* arg;
	struct args_s *next;
} args_t;

args_t *add(args_t **head, char* arg);
size_t print(args_t *head);
char **transform(args_t **head);
pid_t fork(void);

#define UNUSED(x) (void)(x);

#endif
