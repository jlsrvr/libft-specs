#include "../libft.h"
#include <stdio.h>

static void display_result(char *s1, char *s2, char *result, size_t expected_len, int succes)
{
	printf("--------------\n");
	(succes) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("First = \"%s\"\nSecond = \"%s\"\n", s1, s2);
	printf("Result = \"%s\"\n", result);
	printf("length s1 + s2 = %zu length of new %zu\n", expected_len, ft_strlen(result));
	printf("\033[0m");
}

static int check_ft_strjoin(char *s1, char *s2, char *result)
{
	int len_s1;
	int len_s2;
	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	if (s2)
		len_s2 = ft_strlen(s2);
	else
		len_s2 = 0;
	if (ft_strncmp(result, s1, len_s1))
		return (0);
	if (ft_strncmp(&result[len_s1], s2, len_s2))
		return (0);
	return (1);
}

void specs_ft_strjoin(int *succes, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int index1;
	int index2;
	char *s1;
	char *s2;
	size_t expected_len;
	char strs[4][14] = {"adore vraiment", "", " ", "\n"} ;
	char *ptn_result;
	for(index1 = 0; index1 < 4; index1++)
	{
		for(index2 = 0; index2 < 4; index2++)
		{
			s1 = strs[index1];
			s2 = strs[index2];
			ptn_result = ft_strjoin(s1, s2);
			expected_len = (ft_strlen(s1) + ft_strlen(s2));
			if ((ft_strlen(ptn_result) == expected_len) && check_ft_strjoin(s1, s2, ptn_result))
			{
				(*succes)++;
				//display_result(s1, s2, ptn_result, expected_len, 1);
			}
			else
			{
				(*failure)++;
				display_result(s1, s2, ptn_result, expected_len, 0);
			}
			free(ptn_result);
		}
	}
	s1 = NULL;
	s2 = strs[0];
	ptn_result = ft_strjoin(s1, s2);
	expected_len = (0 + ft_strlen(s2));
	if ((ft_strlen(ptn_result) == expected_len) && check_ft_strjoin(s1, s2, ptn_result))
	{
		(*succes)++;
		//display_result(s1, s2, ptn_result, expected_len, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, s2, ptn_result, expected_len, 0);
	}
	free(ptn_result);
	s1 = strs[0];
	s2 = NULL;
	ptn_result = ft_strjoin(s1, s2);
	expected_len = (ft_strlen(s1) + 0);
	if (!ft_strncmp(ptn_result, s1, ft_strlen(s1)))
	{
		(*succes)++;
		//display_result(s1, s2, ptn_result, expected_len, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, s2, ptn_result, expected_len, 0);
	}
	free(ptn_result);
	s1 = NULL;
	s2 = NULL;
	ptn_result = ft_strjoin(s1, s2);
	expected_len = 0;
	if (!ft_strncmp(ptn_result, "", 1))
	{
		(*succes)++;
		//display_result(s1, s2, ptn_result, expected_len, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, s2, ptn_result, expected_len, 0);
	}
	free(ptn_result);
}
