#include "main.h"
/**
 * _strlen - returns the length of a string.
 * ----- From 0x05-pointer_array_strings -----
 * @s: the pointer of the first char in string s
 *
 * Return: the length of a string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0';)
		i++;
	return (i);
}

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest.
 * ---- from 0x05-pointer_array_strings -----
 * @dest: the buffer to copy to
 * @src: the string to copy from
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - concatenates two strings.
 * appends the src string to the dest string
 * overwriting the terminating null byte (\0) at the end of dest
 * and then adds a terminating null byte
 * --- from 0x06-pointer_arrays_strings ----
 * @dest: the destination string to append
 * @src: the source string to append from
 *
 * Return: pointer to the resulting string dest
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strncmp - compares two strings with spicific length.
 * function should work exactly like strncmp
 * Run man strncmp to learn more.
 *
 * @s1: First string
 * @s2: Second string
 * @n: max number of bytes to compare
 *
 * Return: (0) if the s1 and s2 are equal
 * a negative value if s1 is less than s2
 * a positive value if s1 is greater than s2
*/

int _strncmp(char *s1, char *s2, size_t n)
{
	int i = 0;
	int res;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		i++;
		if (i >= (int)n)
			return (0);
	}
	if (*(s1 + i) == *(s2 + i))
		res = 0;
	else
		res = (int)*(s1 + i) - (int)*(s2 + i);
	return (res);
}

/**
 * _strcmp - compares two strings.
 * function should work exactly like strcmp
 * Run man strcmp to learn more.
 *
 * @s1: First string
 * @s2: Second string
 *
 * Return: (0) if the s1 and s2 are equal
 * a negative value if s1 is less than s2
 * a positive value if s1 is greater than s2
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res;

	if (s1 == NULL || s2 == NULL)
		return (1);
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != 0 && *(s2 + i) != 0)
		i++;
	if (*(s1 + i) == *(s2 + i))
		res = 0;
	else
		res = (int)*(s1 + i) - (int)*(s2 + i);
	return (res);
}
