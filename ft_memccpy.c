
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		((char*)dest)[index] = ((char*)src)[index];
		if (((char*)src)[index] == c)
			return (&dest[index + 1]);
		index++;
	}
	return (NULL);
}
