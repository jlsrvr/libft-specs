#include "../libft.h"
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
	int index;
	size_t len;
	char strs[4][14] = {"adore vraiment", "", " ", "\n"} ;
	char *ptn_result;
	for(index = 0; strs[0][index]; index++)
	{
		ptn_result = ft_substr(strs[0], index, 6);
		if ((ft_strlen(ptn_result) <= 6) && !ft_strncmp(&strs[0][index], ptn_result, 6))
		{
			(*succes)++;
			//display_result(strs[0], ptn_result, index, 6, 1);
		}
		else
		{
			(*failure)++;
			display_result(strs[0], ptn_result, index, 6, 0);
		}
		free(ptn_result);
	}
	index = 1;
	len = 6;
	ptn_result = ft_substr(strs[1], index, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&strs[1][index], ptn_result, len))
	{
		(*succes)++;
		//display_result(strs[1], ptn_result, index, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[1], ptn_result, index, 6, 0);
	}
	free(ptn_result);
	index = 3;
	len = 0;
	ptn_result = ft_substr(strs[0], index, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&strs[0][index], ptn_result, len))
	{
		(*succes)++;
		//display_result(strs[0], ptn_result, index, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[0], ptn_result, index, len, 0);
	}
	free(ptn_result);
	index = 0;
	len = 6;
	ptn_result = ft_substr(strs[2], index, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&strs[2][index], ptn_result, len))
	{
		(*succes)++;
		//display_result(strs[2], ptn_result, index, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(strs[2], ptn_result, index, len, 0);
	}
	free(ptn_result);
	index = 15;
	len = 30;
	char *str = "\n\tqwertyuioooasdfghjkzxcvbnm123456@£$%";
	ptn_result = ft_substr(str, index, len);
	if ((ft_strlen(ptn_result) <= len) && !ft_strncmp(&str[index], ptn_result, len))
	{
		(*succes)++;
		//display_result(str, ptn_result, index, len, 1);
	}
	else
	{
		(*failure)++;
		display_result(str, ptn_result, index, len, 0);
	}
	free(ptn_result);
}
