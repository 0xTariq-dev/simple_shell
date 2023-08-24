#include "main.h"
/**
 * main - simple shell interpreter (still developping)
 * @ac: number of arguments (unused)
 * @av: the given argument
 * Return: 0 It shouldn't
*/
int main(int __attribute__((unused)) ac, char **av)
{
	full_cmd c;
	char *line;
	size_t buffsize;
	int i = 0;

	/** Infinite loop for handling the shell */
	while (1)
	{
		/** Handling User Input And Execution */
		line = NULL;
		print_prompt();
		get_input(&line, &buffsize);
		i++;
		c = get_args(line);
		c.Gline = line;
		c.c_cmd_num = i;
		c.prog_name = av[0];
		if (c.cmd != NULL)
		{
			if (!built_in(c))
			{
				c.cmd = _which(c);
				if (c.cmd != NULL)
					exec_cmd(c);
				if (c.cmd == NULL && (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO)))
					return (127);
			/** Freeing Allocated Memory */
				free(c.cmd);
			}
		}
		_free(c.args, line, NULL);
	}
	return (0);
}
