//HEADER

#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		look;

	index = 0;
	if (needle[index] == '\0')
		return ((char*)haystack);
	while (haystack[index] && index <= len)
	{
		look = 0;
		while (haystack[(index + look)] == needle[look] && needle[look] && (index + look) <= len)
			look++;
		if (!needle[look])
			return (&((char*)haystack)[index]);
		index++;
	}
	return (NULL);
}
