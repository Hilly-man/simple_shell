#include "shell.h"

int increment = 0;

/**
 * exec_it - Checks if command is executable.
 * @av: Array of string
 * @args: Array of string
 */
void exec_it(char **av, char **args)
{
	char *fullpath = NULL, *cmd = NULL;

	cmd = av[0];
	if (access(cmd, X_OK) == 0)
		fork_it(cmd, av, args);
	else
	{
		fullpath = findme(cmd);
		if (fullpath == NULL)
			perror(args[0]);
		if (access(fullpath, X_OK) == 0)
			fork_it(fullpath, av, args);
	}
}

/**
 * fork_it - Forks and execute command.
 * @pathname: Command
 * @av: Array of string
 * @args: Array of string
 */
void fork_it(char *pathname, char **av, char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid < 0)
		perror(args[0]);
	else if (pid == 0)
		execve(pathname, av, environ);
	else
		wait(&status);
	if (WIFEXITED(status))
		errno = WEXITSTATUS(status);
}
