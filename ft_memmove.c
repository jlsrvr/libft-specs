//HEADERS

#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t len)
{
	size_t index;

	index = -1;
	while (++index < len)
		((char*)dest)[index] = ((char*)src)[index];
	return (dest);
}
