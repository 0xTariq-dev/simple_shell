#include "main.h"

/**
 * built_in - control built-in commands and execute if match
 * @c: the full command given
 * Return: 1 if the command is a built-in after executing it
 * or 0 if the command is not a built-in
 */
int built_in(full_cmd c)
{
	int i;
	builtin_t builtins[] = {{"exit", our_exit},
				{"env", Print_env}, 
				{NULL, NULL}};

	for (i = 0; (builtins + i)->name != NULL; i++)
	{
		if (strcmp(c.args[0], (builtins + i)->name) == 0)
		{
			(builtins + i)->func(c);
			return (1);
		}
	}
	return (0);
}

void our_exit(full_cmd c)
{
	_free(c.Gline, c.args[0], c.args, NULL);
	exit(0);
}

void Print_env(full_cmd c)
{
	int i = 0;

	c.cmd = _which(c.cmd);
	exec_cmd(c.cmd, c.args);
	if (c.args[1] == NULL)
	{
		for (; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}
}
