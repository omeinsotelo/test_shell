#include "holberton.h"
/**
 * child_process - proccess child.
 *
 *
 *
 */
void check_paths(char **args, char **env)
{
	char *pathtocheck = malloc(100);
	char *cop = malloc(100);
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
	strcpy(cop, args[0]);
	while(paths[pathcounter])
	{
		strcpy(pathtocheck, paths[pathcounter]);
		strcat(pathtocheck, "/");
		strcat(pathtocheck, cop);
		args[0] = pathtocheck;
		printf("%s\n", pathtocheck);
		pathcounter++;
		state = stat(pathtocheck, properties);
		if (state == 0)
		{
			printf("match: %d\n", state);
			child_process(args[0], args, env);
			break;
		}
	}
	printf("command state: %d\n", state);
	(void) env;
}
