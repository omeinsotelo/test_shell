#include "holberton.h"
/**
 * child_process - proccess child.
 *
 *
 *
 */
void check_paths(char **args, char **env)
{
	char  *pathtocheck = malloc(100);
	char *pathvar = malloc(200);
	char *paths[10];
	char *tok;
	int state, pathcounter = 0;
	struct stat *properties = malloc(sizeof(struct stat));
	printf("checking paths\n");
	pathtocheck = strcpy(pathtocheck, args[0]);
	state = stat(pathtocheck, properties);
	strcpy(pathvar, getenv("PATH"));
	printf("PATHS: %s\n", paths);
	tok = strtok(pathvar, ":");

	while(tok)
	{
		paths[pathcounter] = tok;
		tok = strtok(NULL, ":");
		pathcounter++;
	}
	paths[pathcounter] = NULL;
	pathcounter = 0;
	while(paths[pathcounter])
	{
		printf("%s\n", paths[pathcounter]);
		pathcounter++;
	}
	printf("command state: %d\n", state);
	(void) env;
}
