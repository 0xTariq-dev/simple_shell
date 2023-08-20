#include "main.h"

/**
 * exec_cmd - Executes command passed by the shell.
 * @pathname : The path of the command to execute.
 * @argv: The array of arguments passed to the executable.
 *
 * Return: Always 0.
 */
int exec_cmd(const char *pathname, char **argv)
{
	int id;

	/*
	 * Checking if NULL was passed and return,
	 * If a valid pathname was passed fork the process pefore execution
	 */
	if (pathname == NULL)
	{
		perror("Error");
		return (-1);
	}
	else
		id = fork();

	/** Checking for the child process pefore executing */
	if (id == 0)
	{
		/** Checking for execution status and print error if it fails*/
		if (execve(pathname, argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	/** Halting the main process until execution */
	else
	{
		wait(&id);
	}
	return (0);
}
