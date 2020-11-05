//HEADER

#include <string.h>
void *ft_memset(void *str, int c, size_t len)
{
	size_t index;

	index = -1;
	while (++index < len)
		((char*)str)[index] = c;
	return (str);
}
