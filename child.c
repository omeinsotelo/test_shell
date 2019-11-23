#include "holberton.h"
/**
 * child_process - proccess child.
 *
 *
 *
 */
void child_process(char *str, char **args, char **env)
{
	int *wait_status = NULL;
	char *varEnv;
	pid_t child;

	child = fork();
	if (!child)
	{
		if (execve(str, args, env) == -1)
		{
			varEnv = check_paths(args, env);
			if (varEnv != NULL)
			{
				execve(varEnv, args, env);
			}
		}		
	}
	if (child > 0)
	{
		wait(wait_status);
		if (isatty(STDIN_FILENO) == 0)
			exit(1);
	}
}
