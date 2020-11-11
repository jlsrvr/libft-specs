//HEADER

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		index;

	if(!(dest = malloc(sizeof(char) * (ft_strlen((char*)src) + 1))))
		return (NULL);
	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	if (src[index] == '\0')
		dest[index] = 0;
	return (dest);
}
