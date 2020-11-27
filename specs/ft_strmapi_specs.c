#include "../libft.h"
#include <stdio.h>

static char replace_with_s(unsigned int rep, char c);
static char replace_with_end(unsigned int rep, char c);
static char move(unsigned int by, char c);

static void display_result(char const *s, char (*f)(unsigned int, char), char *result, char *describe, int success)
{
	int i;
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("String = \"%s\"\nResult = \"%s\"\n", s, result);
	if (s == NULL || f == NULL)
		printf("\033[0m\n");
	else
	{
		for (i = 0; s[i]; i++)
			printf("(%c) == (%c)\n", (*f)(i, s[i]),  result[i]);
		printf("\033[0m\n");
	}
}

static int check_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *result)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if(!((*f)(i, s[i]) == result[i]))
			return (0);
	}
	return (1);
}

void specs_ft_strmapi(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	char const *s;
	char *ptn_result;
	char *describe;
	char (*func)(unsigned int, char);

	s = NULL;
	func = &replace_with_s;
	describe = "Null string with function";
	ptn_result = ft_strmapi(s, func);
	if (ptn_result == NULL)
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "";
	func = &replace_with_s;
	describe = "Empty string with function";
	ptn_result = ft_strmapi(s, func);
	if (!ft_strncmp(ptn_result, "", 2))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "I'm here";
	func = NULL;
	describe = "Null ptn instead of function with string";
	ptn_result = ft_strmapi(s, func);
	if (!ft_strncmp(ptn_result, s, ((ft_strlen(ptn_result) - ft_strlen(s)) > 0 ? ft_strlen(ptn_result) : ft_strlen(s))))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "";
	func = NULL;
	describe = "Null ptn instead of function with empty string";
	ptn_result = ft_strmapi(s, func);
	if (!ft_strncmp(ptn_result, "", 2))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "I'm a string";
	func = &replace_with_s;
	describe = "Replace all by 's'";
	ptn_result = ft_strmapi(s, func);
	if (check_ft_strmapi(s, func, ptn_result))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "I'm a string";
	func = &replace_with_end;
	describe = "Replace all by \\0";
	ptn_result = ft_strmapi(s, func);
	if (check_ft_strmapi(s, func, ptn_result))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);

	s = "I'm a string";
	func = &move;
	describe = "Move all char by index";
	ptn_result = ft_strmapi(s, func);
	if (check_ft_strmapi(s, func, ptn_result))
	{
		(*sucess)++;
		//display_result(s, func, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, func, ptn_result, describe, 0);
	}
	free(ptn_result);
}

static char replace_with_s(unsigned int n, char c)
{
	(void)c;
	(void)n;
	return ('s');
}

static char replace_with_end(unsigned int n, char c)
{
	(void)c;
	(void)n;
	return (0);
}

static char move(unsigned int by, char c)
{
	c += by;
	if (c > 126)
		c = c - 126;
	return (c);
}
