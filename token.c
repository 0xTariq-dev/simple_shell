#include "main.h"
/**
 * tokenize - tokenize a given string
 * @string: a string to tokinize
 * @delim: a string contain the delimeters
 * note: to free allocated memory
 * 1- free only the first element of argv `argv[0]`
 * 2- free argv
 * Return: a array of strings
 */
char **tokenize(char *string, char *delim)
{
	char **argv;
	char *copystr;
	int toknum, i, ch = 0;

	copystr = malloc(strlen(string) + 1);
	if (!copystr)
	{
		perror("Error: ");
		exit(-1);
	}
	/* Here is a function that need replace */
	strcpy(copystr, string);
	/****************************************/
	strtok(copystr, delim);
	for (toknum = 1; strtok(NULL, delim); toknum++)
	{}
	argv = malloc(sizeof(char *) * (toknum + 1));
	if (!argv)
	{
		perror("Error: ");
		exit(-1);
	}
	argv[0] = copystr;
	for (i = 1; i < toknum; ch++)
	{
		if (copystr[ch] == '\0')
		{
			ch++;
			argv[i] = &copystr[ch];
			i++;
		}
	}
	argv[i] = NULL;
	return (argv);
}

