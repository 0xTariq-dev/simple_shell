#include "main.h"
/**
 * print_illegal - print error message format
 * @c: all what we need in a struct
 * format: <prog_name>: <c>: <command>: <error message>
 */
void print_illegal(full_cmd c)
{
	char dig[1];
	int c_count = c.c_cmd_num;

	write(2, c.prog_name, _strlen(c.prog_name));
	write(2, ": ", 2);
	while (c_count % 10 != 0)
	{
		dig[0] = (c_count % 10) + '0';
		c_count /= 10;
		write(2, dig, 1);
	}
	write(2, ": ", 2);
	write(2, c.cmd, _strlen(c.cmd));
	write(2, ": Illegal number: ", _strlen(": Illegal number: "));
	write(2, c.args[1], _strlen(c.args[1]));
	write(2, "\n", 1);
}
