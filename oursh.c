#include "main.h"
/**
 * main - simple shell (still developping)
 * only the prompt handled right now
 * Return: 0 It shouldn't
*/
int main(void)
{
	char *line;
	size_t buffsize;
	ssize_t strl;
	char *cmd;
	char **argv = NULL;

	while (1)
	{
		line = NULL;
		strl = prompt(&line, &buffsize);
		cmd = malloc(sizeof(char) * strl);
		strncpy(cmd, line, (strl - 1));
		argv = malloc(sizeof(cmd));
		argv[0] = cmd;
		exec_cmd(cmd, argv);
		/* We will need it later but for now */
		(void) strl;
		/**********************/
		free(line);
	}
	return (0);
}
