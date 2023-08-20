#include "main.h"

/**
 * _free - Frees any number of pointers given.
 * @p1: The pointer to be freed.
 *
 * Return: NOTHING
 */
void _free(void *p1, ...)
{
	void *ptr;

	va_list ptrs;

	va_start(ptrs, p1);

	ptr = p1;
	while (ptr != NULL)
	{
		free(ptr);
		ptr = va_arg(ptrs, void*);
	}
	va_end(ptrs);
}
