#include "main.h"

/**
 * Print_env - Handles the `env` command and prints environ variable.
 * @c: A strcture of the given command.
 * Return: Nothing.
 */
void Print_env(full_cmd c)
{
	int i = 0;

	c.cmd = _which(c.cmd);
	exec_cmd(c.cmd, c.args);
	if (c.args[1] == NULL || _strcmp(c.args[1], "-v") == 0)
	{
		for (; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}
	if (c.args[1] != NULL && _strcmp(c.args[1], "-0") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s", environ[i]);
		}
		printf("\n");
	}
	free(c.cmd);
}
/**
 * our_exit - Handles the `exit` comman.
 * @c: A strcture of the given command.
 * Return: Nothing.
 */
void our_exit(full_cmd c)
{
	_free(c.Gline, c.args[0], c.args, NULL);
	exit(0);
}
