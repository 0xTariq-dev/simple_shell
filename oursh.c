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

	(void) strl;

	/** Infinite loop for handling the shell */
	while (1)
	{
		/** Handling User Input And Execution */
		line = NULL;
		strl = prompt(&line, &buffsize);
		c = get_args(line);
		c.cmd = _which(c.cmd);
		exec_cmd(c.cmd, c.args);

		/** Freeing Allocated Memory */
		free(line);
		free(c.args[0]);
		free(c.args);
	}
	return (0);
}
