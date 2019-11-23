#include "holberton.h"

int lenMalloc(char *pointer)
{
	int len = 0;

	while (*(pointer + len) != 0)
		len++;

	return (len);
}

char *_getenv(char *nameVar, char **env)
{
	int i = 0;
	char *valueEnv = env[i];
	char *nameEnv = strtok(valueEnv, "=");

	while(strcmp(nameVar, nameEnv) !=  0 && nameEnv && env[i] != 0)
	{
		valueEnv = env[i++];
		nameEnv = strtok(valueEnv, "=");
	}

	nameEnv = strtok(NULL, "\n");

	if (env[i] == 0)
		return (NULL);

	return (nameEnv);
}

char *check_paths(char **args, char **env)
{
	char *fullPath, *tok;
	char *valueVar = _getenv("PATH", env);
	struct stat properties;
	int i = 0, sizeMalloc = 0;


	if (valueVar == NULL)
		return; //validar error

	tok = strtok(valueVar, ":");

	while(tok)
	{

		sizeMalloc = lenMalloc(tok) + lenMalloc(args[0]) + 1;
		fullPath = malloc(sizeof(char *) * sizeMalloc);

		strcat(fullPath, tok);
		strcat(fullPath, "/");
		strcat(fullPath, args[0]);

		if(stat(fullPath, &properties) == 0)
			return (fullPath);

		tok = strtok(NULL, ":");

		free(fullPath);
	}

	return (NULL);

}
