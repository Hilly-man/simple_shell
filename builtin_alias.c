#include "shell.h"

/**
 * _commandHistory- Display command history list with line numbers, from 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _commandHistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _removeAlias- Remove an alias.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: 0 on success, 1 on error
 */
int _removeAlias(info_t *info, char *str)
{
	char *equalSign, temp;
	int ret;

	equalSign = _strchr(str, '=');
	if (!equalSign)
		return (1);

	temp = *equalSign;
	*equalSign = '\0';
	ret = delete_node_at_index(&(info->alias), get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*equalSign = temp;

	return (ret);
}

/**
 * _setAlias- Set an alias to a string.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: 0 on success, 1 on error
 */
int _setAlias(info_t *info, char *str)
{
	char *equalSign;

	equalSign = _strchr(str, '=');
	if (!equalSign)
		return (1);

	if (!*++equalSign)
		return (removeAlias(info, str));

	removeAlias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _printAlias- Print an alias string.
 * @node: The alias node.
 * Return: 0 on success, 1 on error
 */
int _printAlias(list_t *node)
{
	char *equalSign = NULL, *alias = NULL;

	if (node)
	{
		equalSign = _strchr(node->str, '=');
		for (alias = node->str; alias <= equalSign; alias++)
			_putchar(*alias);

		_putchar('\'');
		_puts(equalSign + 1);
		_puts("'\n");

		return (0);
	}
	return (1);
}

/**
 * _handleAlias- Mimic the alias builtin command.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _handleAlias(info_t *info)
{
	int i = 0;
	char *equalSign = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		equalSign = _strchr(info->argv[i], '=');
		if (equalSign)
			setAlias(info, info->argv[i]);
		else
			printAlias(node_starts_with(info->alias, info->argv[i], '='));

	}

	return (0);
}
