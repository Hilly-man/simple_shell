#include "shell.h"

/**
 * _atoi - Converts a string to integer
 * @str: String
 *
 * Return: Coonverted value on success.
 */
int _atoi(char *str)
{
        int sign = 1, i = 0, res = 0;

        if (str == NULL)
                return (0);
        while (str[i] == ' ')
                i++;
        if (str[i] == '+' || str[i] == '-')
                sign = (str[i++] == '-') ? -1 : 1;
        while (_isdigit(str[i]))
        {
                res = (res * 10) + (str[i] - '0');
                i++;
        }
        return (res * sign);
}

/**
 * _isdigit - Checks if a character is digit.
 * @c: Character
 *
 * Return: Digit value on success.
 */
int _isdigit(int c)
{
        if ((c >= '0') && (c <= '9'))
                return (1);
        else
                return (0);
}
