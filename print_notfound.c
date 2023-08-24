#include "main.h"
/**
 * print_notfound - print error message format
 * @prog_name: the name the the program called by
 * @c: the comulative number of given commands
 * @cmd: the command that is not exist
 * format: <prog_name>: <c>: <error message>
 */
void print_notfound(char *prog_name, int c, char *cmd)
{
	char dig[1];

	write(2, prog_name, _strlen(prog_name));
	write(2, ": ", 2);
	while (c % 10 != 0)
	{
		dig[0] = (c % 10) + '0';
		c /= 10;
		write(2, dig, 1);
	}
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", _strlen(": not found\n"));
}
