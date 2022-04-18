#include "main.h"

/**
 * main - shell
 * @argc - number of arguments
 * @argv - arguments
 * @envp - environment
 */

/*int main(int argc, char *argv[], char *envp[])*/
int main (void)
{
	char *str, **tokens;
	size_t j = 0;
	ssize_t getline2;
	int i = 0;
	command_t built_ins[] = { {"exit", exit2},
				{NULL, NULL} };
	do {
		str = NULL, tokens = NULL;
		j = 0;

		if (write(STDOUT_FILENO, "($) ", 4) == -1)
			dprintf(STDERR_FILENO, "Error printing Stdout");

		getline2 = getline(&str, &j, stdin);
		if (getline2 == -1)
		{
		perror("Error: ");
			free(str);
			if (feof(stdin))
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		tokens = _strtok(tokens, str, " \t\n");
		for (i = 0; built_ins[i].name; i++)
		{
			if (built_ins[i].name == tokens[0])
			{
				if ((built_ins[i].function(tokens)) == 1)
					return (EXIT_SUCCESS);
			}
		}
		if (tokens[0][0] == '/')
			execute(tokens);
		else
		{
			tokens[0] = PATH(tokens[0]);
			if (tokens[0] == NULL)
		perror("Error: ");
			else
				execute(tokens);
		}
	} while (1);
	free(tokens);
	return (0);
}
