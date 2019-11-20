#include "holberton.h"
/**
 * child_process - proccess child.
 *
 *
 *
 */
void child_process(char *str, int get)
{
	char *token;
	int cont, *wait_status = NULL;
	pid_t child;

	cont = 0;
	child = fork();
	if (!child)
	{
		if (execve(av[0], av, NULL) == -1)
			perror("shell");
	}
	if (child > 0)
	{
		wait(wait_status);
		if (isatty(STDIN_FILENO) == 0)
			exit(1);
	}
}
