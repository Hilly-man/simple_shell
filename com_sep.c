#include <shell.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100

int execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
	} else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			char exit_status[10];
			int length = int_to_string(exit_status,
					sizeof(exit_status), WEXITSTATUS(status));
			write(STDERR_FILENO, exit_status, length);
			write(STDERR_FILENO, "\n", 1);
		}
	} return (0);
}

int int_to_string(char *str, size_t size, int num)
{
	if (num == 0)
	{
		str[0] = '0';
		return (1);
	}

	int len = 0;
	int sign = num;

	if (sign < 0)
	{
		num = -num;
		len++;
	}

	while (num != 0)
	{
		str[len++] = '0' + (num % 10);
		num /= 10;
	}

	if (sign < 0)
	{
		str[len++] = '-';
	}

	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];

		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	str[len] = '\0';

	return (len);
}

int main(void)
{
	char input[MAX_COMMANDS * MAX_COMMAND_LENGTH];

	write(STDOUT_FILENO, "Enter commands separated by semicolons (;):\n", 44);
	ssize_t bytes_read = read(STDIN_FILENO, input, sizeof(input));

	if
		(bytes_read <= 0)
	{
	    perror("read failed");
		return (1);
	}
	char *token = strtok(input, ";");

	while (token != NULL)
	{
		execute_command(token);
		token = strtok(NULL, ";");
	}

	return (0);
}
