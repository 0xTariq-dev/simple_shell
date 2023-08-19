#include "main.h"
/**
 * get_envpath - get the path from the environ
 * note: Path should be freed by the user to handle memory leaks
 * Return: PATH environment variable as a string
 * or NULL if PATH variable not found somehow
 */
char *get_envpath()
{
	int i;
	char *Path;
	char varname[] = "PATH=";       /* 5 chars long */

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!_strncmp(varname, environ[i], 5))
		{
			Path = malloc(_strlen(environ[i]) + 1);
			if (Path == NULL)
				exit(-1);
			_strcpy(Path, environ[i]);
			return (Path);
		}
	}
	return (NULL);
}

/**
 * _which - search for a program
 * in the directories in the PATH environment variable
 * @cmd: the program name to search for
 * Return: the full path if found
 * or -1 if not found
 */
char *_which(char *cmd)
{
	char *fullpath;
	char *token;
	char *Path = get_envpath(); /* Calling get_envpath function here */
	struct stat statbuf;
	/* Check if the cmd is aleardy exist */
	if (stat(cmd, &statbuf) == 0)
		return (cmd);
	strtok(Path, "=");
	token = strtok(NULL, ":");
	/* Search in the PATH */
	while (token != NULL)
	{       /* Allocate memory for the potential fullpath and check error */
		fullpath = malloc(_strlen(cmd) + _strlen(token) + 2);
		if (fullpath == NULL)
		{
			free(Path);
			perror("Error: ");
			exit(-1);
		}
		/* Append the cmd to the token in fullpath */
		_strcpy(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, cmd);
		/* Check if the potential fullpath is correct */
		if (stat(fullpath, &statbuf) == 0)
		{       /* If true: end the function */
			free(Path);
			return (fullpath);
		}       /* If false: try again */
		free(fullpath);
		token = strtok(NULL, ":");
	}       /* When it is not exist return NULL */
	free(Path);
	return (NULL);
}
