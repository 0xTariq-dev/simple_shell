#include "main.h"

/**
 * exec_cmd - Executes command passed by the shell.
 * @cmd : The command to execute.
 *
 * Return: Always 0.
 */
int exec_cmd(const char *pathname, char **argv)
{
	int id = fork();

	if (id == 0)
	{
		if (pathname == NULL)
			return (-1);
		if (execve(pathname, argv, NULL) == -1)
		{
			perror("Error");
			exit(98);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
