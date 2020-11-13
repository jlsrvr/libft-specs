//HEADER

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void *dest;

	if((dest = malloc(size * count)))
		return (dest);
	return (NULL);
}
