//HEADER

#include <stdlib.h>

int ft_strlen(char *str);

char *ft_strjoin(char const *s1, char const *s2)
{
	int index;
	char *dest;

	if (!(dest = malloc(sizeof(*dest) * (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1))))
		return (NULL);
	index = 0;
	while (*s1)
	{
		dest[index++] = *s1;
		s1++;
	}
	while (*s2)
	{
		dest[index++] = *s2;
		s2++;
	}
	dest[index] = 0;
	return (dest);
}
