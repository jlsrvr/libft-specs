//HEADERS

#include <string.h>

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t index;

	index = -1;
	while (++index < n)
		((char*)dest)[index] = ((char*)src)[index];
	return (dest);
}
