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
	free(c.Gline);
	free(c.args[0]);
	free(c.args);
	exit(0);
}
