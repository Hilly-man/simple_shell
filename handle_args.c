#include "shell.h"

/**
 * _split - Splits a string into tokens.
 * @str: String
 * @delim: Delimiter
 *
 * Return: An array of string on success,
 * and NULL on failure.
 *
 * NOTE: Functions prefixed with an underscore
 * (_) are collaborators' defined functions.
 */
char **_split(char *str, const char *delim)
{
        char *str_cpy, *token, **av = NULL;
        size_t str_count = 0, i = 0;

        if ((str == NULL) || (delim == NULL))
        {
                return (NULL);
        }
        str_cpy = _strdup(str);
	if (str_cpy == NULL)
		return (NULL);
        token = strtok(str, delim);
        while (token != NULL)
        {
                str_count++;
                token = strtok(NULL, delim);
        }
        str_count++;
        av = malloc(str_count * sizeof(char *));
	if (av == NULL)
	{
		free(str_cpy);
		return (NULL);
	}
        token = strtok(str_cpy, delim);
        while (token != NULL)
        {
                av[i] = malloc((_strlen(token) + 1) * sizeof(char));
                _strcpy(av[i], token);
                i++;
                token = strtok(NULL, delim);
        }
        av[i] = NULL;
        free(str_cpy);
        return (av);
}

/**
 * findme - Finds the full PATH of cmd.
 * @cmd: A command
 *
 * Return: Full PATH of cmd on success,
 * and NULL on failure.
 */
char *findme(char *cmd)
{
        char *dir = NULL, *path = NULL, *fullpath = NULL, *delim = NULL;
        int i = 0;

        delim = ":";
        while (environ[i] != NULL)
        {
                if (_strncmp(environ[i], "PATH=", 5) == 0)
                {
                        break;
                }
                i++;
        }
        path = _strdup(environ[i] + 5);
        if (path == NULL)
        {
                printf("Path strdup\n");
                return (NULL);
        }
        dir = strtok(path, delim);
        while (dir != NULL)
        {
                fullpath = malloc(_strlen(dir) + _strlen(cmd) + 2);
                if (fullpath == NULL)
                {
                        free(path);
                        return (NULL);
                }
                _memcpy(fullpath, dir, _strlen(dir));
                _strcat(fullpath, "/");
                _strcat(fullpath, cmd);
                if (access(fullpath, X_OK) == 0)
                {
                        free(path);
                        return (fullpath);
                }
                dir = strtok(NULL, delim);
        }
        free(path);
        return (NULL);
}

/**
 * arr_count - Gets the total element in an array.
 * @args: An array
 *
 * Return: Total number of element on success,
 * and -1 on failure.
 */
int arr_count(char **args)
{
        int count = 0;

        if (args == NULL)
        {
                return (-1);
        }
        while (args[count] != NULL)
        {
                count++;
        }
        return (count);
}
