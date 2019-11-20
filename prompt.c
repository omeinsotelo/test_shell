#include "holberton.h"

int main(int ac, char **argv, char **envp)
{
	char *str, *av[10], *token;
	size_t count, flag;
	int get, cont = 0;

	(void) ac;
	(void) argv;
	flag = 1;
	count = 0;
	while (flag)
	{
		write(STDOUT_FILENO, "$ ", 2);
		get = getline(&str, &count, stdin);
		printf("process: %d\n", getpid());
		if (get == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(1);
		}
		token = strtok(str, "\t\n\r ");
                while (token)
		  {
		    av[cont] = token;
		    token = strtok(NULL, "\t\n\r ");
		    cont++;
		  }
                av[cont] = NULL;
		printf("should enter to check\n");
		check_paths(av, envp);
		/*child_process(str, get);*/
	}
	return (0);

}
