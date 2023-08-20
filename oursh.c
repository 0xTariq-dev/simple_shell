#include "main.h"
/**
 * main - simple shell (still developping)
 * only the prompt handled right now
 * Return: 0 It shouldn't
*/
int main(void)
{
	full_cmd c;
	char *line;
	size_t buffsize;
	ssize_t strl;

	/** Infinite loop for handling the shell */
	while (1)
	{
		/** Handling User Input And Execution */
		line = NULL;
		strl = prompt(&line, &buffsize);
		if (strl != 1)
		{
			c = get_args(line);
			c.Gline = line;
			if (!built_in(c))
			{
				c.cmd = _which(c.cmd);
				exec_cmd(c.cmd, c.args);

			/** Freeing Allocated Memory */
				free(c.cmd);
			}
			_free(c.args[0], c.args, NULL);
		}
		free(line);
	}
	return (0);
}
