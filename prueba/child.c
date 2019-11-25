#include "holberton.h"

int main(int ac, char **argv, char **env)
{
	char *arg[10], *str;
	int *wait_status = NULL, flag = 1;
	pid_t child;
	struct stat stat_var;
	(void)ac;
	(void)argv;

	signal(SIGINT, control);

	while (flag)
	{
		get_arguments(arg);

		child = fork();
		if (!child)
		{
			str = arg[0];

			if (stat(arg[0], &stat_var) != 0)
				str = check_paths(arg, env);

			if (execve(str, arg, env) == -1)
				perror("Error");
		}

		if (child > 0)
		{
			wait(wait_status);
			if (isatty(STDIN_FILENO) == 0)
				exit(1);
		}
	}

	return (0);
}

void control(int fn_signal)
{
	(void)fn_signal;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}
