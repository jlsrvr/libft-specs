//HEADER

#include <string.h>

int ft_strlen(char *str);

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t lensrc;
	size_t index;

	lensrc = (size_t)ft_strlen((char*)src);
	index = 0;
	if (dstsize < 1)
		return (lensrc);
	while ((index < (dstsize - 1)) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (lensrc);
}
