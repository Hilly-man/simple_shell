#include "shell.h"

/**
 * _free - Frees an array of string
 * @argv: An array of string
 */
void _free(char **argv)
{
        int i = 0;

        if (argv == NULL)
        {
                return;
        }
        while (argv[i] != NULL)
        {
                free(argv[i]);
                i++;
        }
        free(argv);
}

/**
 * cleaner - Frees all allocated space
 * @buff_rd: Buffer read
 * @fpath: Full path
 * @av: Array of argument
 */
void cleaner(char *buff_rd, char **av)
{
        free(buff_rd);
        _free(av);
}
