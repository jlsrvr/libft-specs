#include "../libft.h"
#include <stdio.h>

static void display_result(char *s1, char *set, char *result, int succes)
{
	printf("--------------\n");
	(succes) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("String = \"%s\"\nSet = \"%s\"\n", s1, set);
	printf("Result = \"%s\"\n", result);
	printf("\033[0m");
}

int check_ft_strtrim(char *s1, char *expected)
{
	return(!((int)ft_strncmp(s1, expected, 30)));
}

void specs_ft_strtrim(int *succes, int *failure)
{
	char *s1;
	char *set;
	char strs[5][30] = {"   adore\tvraiment   ", "adore vraiment", "", " ", "\t"} ;
	char *ptn_result;
	s1 = strs[0];
	set = strs[0];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, strs[2]))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[0];
	set = strs[1];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, strs[4]))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[0];
	set = strs[2];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, strs[0]))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[1];
	set = strs[3];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, s1))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[2];
	set = strs[3];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, s1))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[3];
	set = strs[2];
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, s1))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = strs[1];
	set = NULL;
	ptn_result = ft_strtrim(s1, set);
	if (check_ft_strtrim(ptn_result, s1))
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
	s1 = NULL;
	set = strs[2];
	ptn_result = ft_strtrim(s1, set);
	if (ptn_result == NULL)
	{
		(*succes)++;
		//display_result(s1, set, ptn_result, 1);
	}
	else
	{
		(*failure)++;
		display_result(s1, set, ptn_result, 0);
	}
	free(ptn_result);
}
