#include "shell.h"

int main(int ac __attribute__((unused)), char **args)
{
        char *buff_rd = NULL, **av = NULL;
        const char *pmt = "$ ", *delim = " \n";
        size_t n_chars = 0;
        ssize_t total_chars;
	int fd;

	if (isatty(STDIN_FILENO))
	{
		fd = 1;
		_puts(pmt);
	}
	else
		fd = 0;
	errno = 0;
	while (((total_chars = getline(&buff_rd, &n_chars, stdin)) != -1))
	{
		fflush(stdout);
		if ((total_chars  == -1) && (isatty(STDIN_FILENO)))
		{
			_putchar('\n');
			break;
		}
		av = _split(buff_rd, delim);
		exec_it(av, args);
		env_print(av, args);
		if (fd)
			_puts(pmt);
	}
	cleaner(buff_rd, av);
	return (0);
}
