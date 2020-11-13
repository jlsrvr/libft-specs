//HEADER

#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	(void)s;
	(void)start;
	char *dest;
	size_t index;

	if(!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	index = 0;
	while (s[index + start] && (len != index))
		{
			dest[index] = s[index + start];
			index++;
		}
	dest[index] = 0;
	return (dest);
}
