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
	/** Forking the process pefore exexuting */
	int id = fork();

	/** Checking for the child process pefore executing */
	if (id == 0)
	{
		/** Return error if NULL was passed */
		if (pathname == NULL)
			return (-1);
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
