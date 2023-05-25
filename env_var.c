#include "shell.h"

/**
 * _display_env - Prints the current environment.
 * @info: Structure containing relevant arguments for the function.
 * Return: Always 0.
 */
int _display_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * *_getenv_var - Gets the value of an environment variable.
 * @info: Structure containing relevant arguments for the function.
 * @name: Name of the environment variable.
 * Return: The value of the environment variable.
 */
char *_getenv_var(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
	p = starts_with(node->str, name);
	if (p && *p)
		return (p);
	node = node->next;
	}
	return (NULL);
}

/**
 * _initenv_var - Initializes a new environment variable
 * or modifies an existing one.
 * @info: Structure containing relevant arguments for the function.
 * Return: Always 0.
 */
int _initenv_var(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _remunsetenv - Removes an environment variable.
 * @info: Structure containing relevant arguments for the function.
 * Return: Always 0.
 */
int _remunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
	_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; info->argv[i]; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * add_env_list - Populates the linked list of environment variables.
 * @info: Structure containing relevant arguments for the function.
 * Return: Always 0.
 */
int add_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
