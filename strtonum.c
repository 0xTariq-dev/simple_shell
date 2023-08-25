/**
 * _isdigit - is a function that checks for a digit (0 through 9)
 *
 * @c: The character to check
 * Return: 1 if c is a digit
 * otherwise return 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * strtonum - convert a string to an integer
 * @s: the string to convert
 * Return: an integer converted from the string
 * if there is a character return -1
*/
int strtonum(char *s)
{
	int num = 0;

	while (*s != '\0')
	{
		if (!_isdigit(*s))
			return (-1);
		if (num > 0)
			num *= 10;
		num += (*s - '0');
		s++;
	}
	return (num);
}
