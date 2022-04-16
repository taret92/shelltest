#include "main.h"

/**
 * find_path - searc the commands in path
 * @comm: Commands
 * Return: 0
 */

char *PATH(char *comm)
{
	extern char **environ;
	char *dup = NULL; 
  char **env = environ;
	char **funclist = malloc(1024), *funcs = NULL;
	struct stat stats;
	int count = 0, i = 0;

	for (count = 0; env[count] != NULL; count++)
	{
		if ((strncmp("PATH", env[count], 4)) == 0)
			break;
	}
	dup = malloc(strlen(env[count]) + 1);
	strcpy(dup, env[count]);
	funcs = strtok(dup, ":=");
	while (funcs != NULL)
	{
		funclist[i] = strdup(funcs);
		strcat(funclist[i], "/");
		strcat(funclist[i], comm);
		if (stat(funclist[i], &stats) == 0)
		{
			free(dup);
			return (funclist[i]);
		}
		i++;
		funcs = strtok(NULL, ":");
	}
	free(dup);
	free(funclist);
	return (NULL);
}
