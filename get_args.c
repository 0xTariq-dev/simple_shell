#include "main.h"

/**
 * token_num - get number of tokens in a string
 * @str: the string
 * @delim: the delimiter to tokenize by
 * Return: number of tokens in the string or -1 on fail
 * note: the function doesn't change the original string.
 */
int token_num(char *str, char *delim)
{
	char *copystr;
	int num = 0;

	if (str == NULL || delim == NULL)
		return (-1);
	copystr = malloc(_strlen(str) + 1);
	if (!copystr)
	{
		perror("Error");
		exit(-1);
	}
	_strcpy(copystr, str);
	if (strtok(copystr, delim) != NULL)
		num = 1;
	while (strtok(NULL, delim))
		num++;
	free(copystr);
	return (num);
}

/**
 * tokenize - tokenize a given string
 * @string: a string to tokinize
 * note: to free allocated memory
 * 1- free only the first element of argv `argv[0]`
 * 2- free argv
 * Return: a array of strings
 */
char **tokenize(char *string)
{
	char **argv;
	char *token;
	int toknum, i;
	char delim[] = {' ', '\t', '\n'};
	/* Get number of tokens to allocate memory for */
	toknum = token_num(string, delim);
	/* Allocate memory for tokens and check fail */
	argv = malloc(sizeof(char *) * (toknum + 1));
	if (!argv)
	{
		perror("Error");
		exit(-1);
	}
	/* Assign the tokens to the array elements */
	if (toknum == 0)
	{
		argv[0] = NULL;
		return (argv);
	}
	else
	{
		token = strtok(string, delim);
		argv[0] = token;
		for (i = 1; i < toknum; i++)
			argv[i] = strtok(NULL, delim);
		argv[i] = NULL;
		return (argv);
	}
}

/**
 * get_args - split the line given to the shell into a command and arguments.
 * @line: The full line passed to the program.
 *
 * Return: A structure of the command and arguments
 */
full_cmd get_args(char *line)
{
	full_cmd c;
	/** Intializing the structure and allocating it's memory */
	c.args = tokenize(line);
	c.cmd = c.args[0];
	return (c);
}
