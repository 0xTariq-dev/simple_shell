#include "main.h"

/**
 * Print_env - Handles the `env` command and prints environ variable.
 * @c: A strcture of the given command.
 * Return: Nothing.
 */
void Print_env(full_cmd c)
{
	int i = 0;

	if (c.args[1] == NULL || _strcmp(c.args[1], "-v") == 0)
	{
		for (; environ[i] != NULL; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
		}
	}
	if (_strcmp(c.args[1], "-0") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
		}
		write(1, "\n", 1);
	}
}

/**
 * our_exit - Handles the `exit` comman.
 * @c: A strcture of the given command.
 * Return: Nothing.
 */
void our_exit(full_cmd c)
{
	int st = 0;

	if (c.args[1] != NULL)
	{
		st = strtonum(c.args[1]);
		if (st == -1)
		{
			print_illegal(c);
			_free(c.Gline, c.args, NULL);
			exit(2);
		}
		_free(c.Gline, c.args, NULL);
		exit(st);
	}
	else
	{
		_free(c.Gline, c.args, NULL);
		exit(st);
	}
}
