//HEADER

#include <string.h>
int ft_strlen(char *str);

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lendst;
	size_t lensrc;
	size_t index;

	lendst = (ft_strlen((char*)dst));
	lensrc = (ft_strlen((char*)src));
	index = 0;
	if (lendst >= dstsize)
		return (dstsize + lensrc);
	while ((lendst + index) < dstsize - 1 && src[index])
	{
		dst[(lendst + index)] = src[index];
		++index;
	}
	dst[(lendst + index)] = '\0';
	return (lendst + lensrc);
}
