#include "main.h"
/**
 * print_prompt - print a prompt if in interactive mode.
 */
void print_prompt(void)
{
	char prmpt[] = "$ ";
	int len = _strlen(prmpt);

	/* Printing the prompt */
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(1, prmpt, len);
}
