#include "shell.h"

/** exit_shell - Exits the shell.
 * @buff_rd: Getline string
 * @av: Array of argument
 * @args: Array of argument
 */
void exit_shell(char *buff_rd, char **av, char **args)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		if (arr_count(av) == 1)
		{
			cleaner(buff_rd, av);
			exit(errno);
		}
		else if (arr_count(av) == 2)
		{
			if (_atoi(av[1]) != 0)
			{
				cleaner(buff_rd, av);
				exit(_atoi(av[1]));
			}
			else
				perror(args[0]);
		}
		else
			perror(args[0]);
	}
	else
		perror(args[0]);
}

/**
 * env-print - Checks if command is environ.
 * @av: Array of string
 * @args: Array of string
 */
void env_print(char **av, char **args)
{
	if (_strcmp(av[0], "env") == 0)
	{
		if (av[1] != NULL)
			print_env();
		else
			perror(args[0]);
	}
}
