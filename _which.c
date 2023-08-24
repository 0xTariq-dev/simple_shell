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
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: given string
 *
 * Return: a pointer to memory space with the copy of the string
 * or exit with value -1 if failed.
*/

char *_strdup(char *str)
{
	int i;
	char *dup = malloc(_strlen(str) + 1);

	if (dup == NULL)
	{
		perror("Error");
		exit(-1);
	}
	for (i = 0; str[i] != '\0'; i++)
		*(dup + i) = *(str + i);
	*(dup + i) = *(str + i);
	return (dup);
}

/**
 * _which - search for a program
 * in the directories in the PATH environment variable
 * @c: all what we need
 * Return: the full path if found
 * or NULL if not found
 */
char *_which(full_cmd c)
{
	char *fullpath;
	char *token;
	char *Path;
	struct stat statbuf;
	/* Check if the c.cmd is aleardy exist */
	if (stat(c.cmd, &statbuf) == 0)
		return (_strdup(c.cmd));
	Path = get_envpath();	/* Calling get_envpath function here */
	strtok(Path, "=");
	token = strtok(NULL, ":");
	/* Search in the PATH */
	while (token != NULL)
	{       /* Allocate memory for the potential fullpath and check error */
		fullpath = malloc(_strlen(c.cmd) + _strlen(token) + 2);
		if (fullpath == NULL)
		{
			free(Path);
			perror("Error: ");
			exit(-1);
		}	/* Append the c.cmd to the token in fullpath */
		_strcpy(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, c.cmd);
		/* Check if the potential fullpath is correct */
		if (stat(fullpath, &statbuf) == 0)
		{       /* If true: end the function */
			free(Path);
			return (fullpath);
		}       /* If false: try again */
		free(fullpath);
		token = strtok(NULL, ":");
	}       /* When it is not exist print error and return NULL */
	free(Path);
	print_notfound(c.prog_name, c.c_cmd_num, c.cmd);
	return (NULL);
}
