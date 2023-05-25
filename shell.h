#
fndef SHELL_H
#define SHELL_H

/* FUNCTION HEADERS */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* FUNCTION PROTOTYPES */
int _puts(const char *str);
int _putchar(int c);
char **_split(char *str, const char *delim);
void _free(char **argv);
char *_strcat(char *dest, const char *src);
ssize_t _strlen(const char *str);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
void cleaner(char *buff_rd, char **av);
int arr_count(char **args);
int _atoi(char *str);
int _isdigit(int c);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);
char *findme(char *cmd);
void exec_it(char **av, char **args);
void fork_it(char *pathname, char **av, char **args);
void exit_shell(char *buff_rd, char **av, char **args);
void print_env(void);
void env_print(char **av, char **args);
int _cd(info_t *);
int _showHelp(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
#endif
