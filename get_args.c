#include "main.h"

/**
 * get_args - split the line given to the shell into a command and arguments.
 * @line: The full line passed to the program.
 *
 * Return: A structure of the command and arguments
 */
full_cmd get_args(char *line)
{
	full_cmd c;
	char **argv;
	int i = 0;

	/** Intializing the structure and allocating it's memory */
	argv = tokenize(line);
	c.cmd = argv[0];
	c.args = argv;

	/** Checking if allocation didn't happen and print Error */
	if (!c.cmd)
	{
		perror("Error: ");
		exit(-1);
	}
	if (!c.args)
	{
		perror("Error: ");
		exit(-1);
	}

	/** Assigning the arguments to args array */
	while (argv[i] != NULL)
	{
		c.args[i] = argv[i];
		i++;
	}
	c.args[i] = NULL;

	return (c);
}
