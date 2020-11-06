//HEADER

#include <stdio.h>

void *ft_memchr(const void *str, int c, size_t n)
{
	size_t index;

	index = -1;
	while (++index < n)
	{
		if (((char*)str)[index] == c)
			return (&((char*)str)[index]);
	}
	return (NULL);
}
