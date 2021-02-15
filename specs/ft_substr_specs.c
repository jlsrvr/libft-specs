#include "../srcs/libft.h"
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len);

void display_result(char *original, char *new, int start, size_t len, int succes)
{
	printf("--------------\n");
	(succes) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Original = \"%s\"\n     New = \"%s\"\n", original, new);
	printf("start index = %d\n", start);
	printf("length max = %zu actual length %zu\n", len, ft_strlen(new));
	printf("\033[0m");
}

void specs_ft_substr(int *succes, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int start;
	size_t len;
	char strs[4][14] = {"adore vraiment", "", " ", "\n"} ;
	char *ptn_result;
	for(start = 0; strs[0][start]; start++)
	{
		ptn_result = ft_substr(strs[0], start, 6);
		if ((ft_strlen(ptn_result) <= 6) && !ft_strncmp(&strs[0][start], ptn_result, 6))
		{
			(*succes)++;
			//display_result(strs[0], ptn_result, start, 6, 1);
		}
		else
		{
			(*failure)++;
			display_result(strs[0], ptn_result, start, 6, 0);
		}
		free(ptn_result);
	}
	start = 1;
	len = 6;
	ptn_result = ft_substr(NULL, start, len);
	if (ptn_result == NULL)
	{
		(*succes)++;
		//display_result(strs[1], ptn_result, start, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[1], ptn_result, start, 6, 0);
	}
	free(ptn_result);
	start = 3;
	len = 0;
	ptn_result = ft_substr(strs[0], start, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&strs[0][start], ptn_result, len))
	{
		(*succes)++;
		//display_result(strs[0], ptn_result, start, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[0], ptn_result, start, len, 0);
	}
	free(ptn_result);
	start = 0;
	len = 6;
	ptn_result = ft_substr(strs[2], start, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&strs[2][start], ptn_result, len))
	{
		(*succes)++;
		//display_result(strs[2], ptn_result, start, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[2], ptn_result, start, len, 0);
	}
	free(ptn_result);
	start = 15;
	len = 30;
	char *str = "\n\tqwertyuioooasdfghjkzxcvbnm123456@£$%";
	ptn_result = ft_substr(str, start, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&str[start], ptn_result, len))
	{
		(*succes)++;
		//display_result(str, ptn_result, start, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(str, ptn_result, start, len, 0);
	}
	free(ptn_result);
	start = 15;
	len = 30;
	char *s = "une string";
	ptn_result = ft_substr(s, start, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp("", ptn_result, len))
	{
		(*succes)++;
		//display_result(s, ptn_result, start, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, ptn_result, start, len, 0);
	}
	free(ptn_result);
}
