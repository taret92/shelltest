#include "main.h"
/**
 * @param argc
 * @param argv
 * @param env
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	{
	pid_t pid;
	int read;
	int tty = 1;
	int ret;
	int status;
	size_t len = 0;
	char *line, *cpy, *arg, **args;
	args_t *arguments = NULL;
	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do {
		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : 0;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			return (-1);
		}
		cpy = strdup(line);
		for (; (arg = strtok(cpy, " \t\n")); cpy = NULL)
		{
			if (arg == NULL)
			{
				break;
			}
			add(&arguments, arg);
		}
		/*SACAR EN OTRA FUNCION*/
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			args = transform(&arguments);
			ret = execve(args[0], args, env);
			if (ret == -1)
			return (-1);
		}
	else
	{
		wait(&status);
	}
		arguments = NULL;

	} while (1);
	return (0);
	}
}
