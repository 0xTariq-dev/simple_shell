#include "main.h"

/**
 * exec_cmd - Executes command passed by the shell..
 * @c: struct that have all what we need
 * Return: Always 0.
 */
int exec_cmd(full_cmd c)
{
	int id;

	id = fork();
	/** Checking for the child process pefore executing */
	if (id == 0)
	{
		/** Checking for execution status and print error if it fails*/
		if (execve(c.cmd, c.args, NULL) == -1)
		{
			print_err_m(c.prog_name, c.c_cmd_num);
			perror("");
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
