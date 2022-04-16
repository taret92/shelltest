#include "main.h"
/**
 * _strtok - tokens the string.
 * @tokens: Array contains the tokens.
 * @str: string.
 * @delim: delimiter
 * Return: tokens.
 */

char **_strtok(char **tokens, char *str, char *delim)
{
	char *token2 = NULL;
	int i = 0;

	tokens = malloc(10 * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		free(str);
		return (NULL);
	}

	token2 = strtok(str, delim);
	while (token2 != NULL)
	{
		tokens[i] = token2;
		i++;
		token2 = strtok(NULL, delim);
	}
	tokens[i + 1] = NULL;
	free(token2);
	return (tokens);
}

/**
 * exit2 - exit
 * @tokens: tokens.
 * Return: 0
 */

int exit2(char **tokens)
{
	free(tokens);
	return (1);
}
