#include "main.h"
/**
 * get_input - gets a line and check if it is the end.
 * @line: a pointer to the cmd line string
 * @buffsize: a pointer to the buffer size created for the line
 * Return: number of chars of the cmd line
 */

ssize_t get_input(char **line, size_t *buffsize)
{
	ssize_t strl;
	/* Take the command from the user and check for errors */
	strl = getline(line, buffsize, stdin);
	if (strl == -1)
	{
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			write(1, "\n", 1);
		free(*line);
		exit(0);
	}
	return (strl);
}
