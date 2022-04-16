#include "main.h"

/**
 * execute - executes the command.
 * @tokens: array that contains tokens
 * Return: Nothing.
 */

void execute(char **tokens)
{
	pid_t fork2, wait2; 
	fork2 = fork();

	if (fork2 == -1)
	{
		free(tokens);
	}

	if (fork2 == 0)
	{
		if (execv(tokens[0], tokens) == -1)
		{
			free(tokens);
		}
	}

	if (fork2 != 0)
	{
		wait2 = wait(NULL);
		if (wait2 == -1)
			free(tokens);
	}
}
