#include "main.h"
/**
 * prompt - print a prompt and take a command
 * @line: a pointer to the cmd line string
 * @buffsize: a pointer to the buffer size created for the line
 * Return: number of chars of the cmd line
 */
ssize_t prompt(char **line, size_t *buffsize)
{
	ssize_t strl;

	/* Printing the prompt */
	write(1, "($) ", 4);
	/* Take the command from the user and check for errors */
	strl = getline(line, buffsize, stdin);
	if (strl == -1)
	{
		printf("Exiting\n");
		free(*line);
		exit(-1);
	}
	return (strl);
}
