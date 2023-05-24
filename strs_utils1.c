#include "shell.h"

/**
 * _memcpy - Copies memory area.
 * @dest: Destination string.
 * @src: Source string.
 * @n: Number of characters to copy from src.
 *
 * Return: Pointer to dest.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
        char *de_st = (char *) dest;
        const char *s_rc = (const char *) src;
        size_t i = 0;

        if ((dest == NULL) || (src == NULL) || (n == 0))
        {
                return (NULL);
        }
        while (i < n)
        {
                de_st[i] = s_rc[i];
                i++;
        }
        return (dest);
}

/**
 * _putchar - Writes a character to stdout.
 * @c: Character
 *
 * Return: Character written to stdout on success
 *
 * NOTE: Functions prefixed with an underscore
 * (_) are collaborators' defined functions.
 */
int _putchar(int c)
{
        return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - Writes string to stdout.
 * @str: String
 *
 * Return: Total number of characters in string on success
 *
 * NOTE: Functions prefixed with an underscore
 * (_) are collaborators' defined functions.
 */
int _puts(const char *str)
{
        int count = 0;

        while (str[count] != '\0')
        {
                write(STDOUT_FILENO, &str[count], 1);
                count++;
        }
        return (count);
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: The concatenated string on success,
 * and NULL on failure.
 */
char *_strcat(char *dest, const char *src)
{
        char *d;
        int i = 0;

        if ((dest == NULL) || (src == NULL))
        {
                return (NULL);
        }
        d = dest;
        while (*d != '\0')
        {
                d++;
        }
        while (src[i] != '\0')
        {
                *d = src[i];
                d++;
                i++;
        }
        *d = '\0';
        return (dest);
}
