// HEADERS

#include <string.h>

void ft_bzero(void *str, size_t n)
{
	size_t index;

	index = -1;
	while (++index < n)
		((char*)str)[index] = 0;
}
