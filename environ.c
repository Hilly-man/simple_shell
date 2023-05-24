#include "shell.h"

/**
 * print_env - Prints environmental variables.
 */
void print_env(void)
{
        int i = 0;

        while (environ[i] != NULL)
        {
                _puts(environ[i]);
                i++;
        }
        _putchar('\n');
}
