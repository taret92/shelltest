#include "main.h"

/**
 * main - shell
 * @argc - number of arguments
 * @argv - arguments
 * @envp - environment
 */

int main(void)
{
	char *str = NULL, **tokens;
	size_t j = 0;
	int i = 0, getline2, tty = 1;
	command_t built_ins[] = {{"exit", exit2},
							 {NULL, NULL}};
	
	if(isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		str = NULL, tokens = NULL;
		j = 0;

		if (tty == 1)
			write(STDOUT_FILENO, "($) ", 4);
		fflush(stdin);

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

		printf("El comando es: %s\n", str);
		if (str == NULL)
		{
			continue;
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
		if (!tokens[0])
		{
			free(tokens);
			free(str);
			continue;
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
