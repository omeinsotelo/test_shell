
#include "holberton.h"

void get_arguments(char **av)
{

	char *str, *token;
	size_t count = 0;
	int get, cont = 0;

    do
    {
	    write(STDOUT_FILENO, "$ ", 2);
	    get = getline(&str, &count, stdin);

	    if (get == EOF)
	    {
		    write(STDOUT_FILENO, "\n", 1);
		    exit(1);
	    }

    } while (get == 1);

    token = strtok(str, "\t\n\r ");
    while (token)
    {
	    av[cont] = token;
	    token = strtok(NULL, "\t\n\r ");
	    cont++;
    }

    av[cont] = NULL;
}
