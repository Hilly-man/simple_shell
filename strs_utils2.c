#include "shell.h"

/**
 * _strcmp - Compares two strings.
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if str1 and str2 are equal,
 * a negative value if str1 < str2,
 * and positive value if str1 > str2.
 */
int _strcmp(char *str1, char *str2)
{
        int i = 0;

        while (str1[i] != '\0' && str2[i] != '\0')
        {
                if (str1[i] != str2[i])
                        return (str1[i] - str2[i]);
                i++;
        }
        return (str1[i] - str2[i]);
}
#include "shell.h"

/**
 * _strcpy - Copies a string.
 * @dest: Destination
 * @src: Source
 *
 * Return: Pointer to dest on success,
 * and NULL on failure.
 */
char *_strcpy(char *dest, const char *src)
{
        ssize_t len;

        if (src == NULL)
        {
                return (NULL);
        }
        len = (_strlen(src));
        _memcpy(dest, src, len);
        dest[len++] = '\0';
        return (dest);
}
#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @str: String
 *
 * Return: Pointer to str on success,
 * and NULL on failure.
 */
char *_strdup(const char *str)
{
        char *dup;
        ssize_t len;

        if (str == NULL)
        {
                return (NULL);
        }
        len = (_strlen(str) + 1);
        dup = malloc(len * sizeof(char));
        _memcpy(dup, str, len);
        return (dup);
}
#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 * @str: String
 *
 * Return: Total number of characters in str.
 */
ssize_t _strlen(const char *str)
{
        ssize_t total_chars = 0;

        while (str[total_chars] != '\0')
        {
                total_chars++;
        }
        return (total_chars);
}
#include "shell.h"

/**
 * _strncmp - Compares part of string str1 with str2.
 * @str1: String
 * @str2: String
 * 
 * Return: 0 on success.
 */
int _strncmp(char* str1, char* str2, size_t n)
{
	size_t i = 0;

        for (i = 0; i < n; i++)
        {
                if (str1[i] != str2[i])
                {
                        return (str1[i] - str2[i]);
                }
                if (str1[i] == '\0')
                {
                        return (0);
                }
        }
        return (0);
}
