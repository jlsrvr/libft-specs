//HEADERS

#include <stdio.h>

void *ft_memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
	size_t index;

	index = -1;
	while (++index < n)
	{
		((char*)dest)[index] = ((char*)src)[index];
		if (((char*)src)[index] == c)
			return (&dest[index + 1]);
	}
	return (NULL);
}
