#include "../libft.h"
#include <stdio.h>
#include <string.h>

static void display_result(char const *s, char c, char **result, char *describe, int success)
{
	int i;
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("String = \"%s\"\nSeparator = \"%c\"\n", s, c);
	printf("Result = ");
	for (i = 0; result[i]; i++)
		printf("%d. \"%s\"\n", i, result[i]);
	printf("%d. %s\n", i, result[i]);
	printf("\033[0m");
}

static int check_ft_split(char ** expected, char ** got)
{
	for (; *expected; expected++, got++)
	{
		if (*got == NULL || strcmp(*expected, *got))
			return (0);
	}
	return (1);
}

static void	free_result(char **result)
{
	int i;
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result[i]);
	free(result);
}

void specs_ft_split(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	char const *s;
	char c;
	char **ptn_result;
	char *describe;

	s = NULL;
	c = 's';
	describe = "Null string";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[1]){NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "";
	c = 's';
	describe = "Empty string";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[1]){NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "STring";
	c = 's';
	describe = "Separator not in string";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[2]){(char*)s, NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "sonetwothreefour";
	c = 's';
	describe = "Separator beginning";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[2]){"onetwothreefour", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "onestwosthreesfour";
	c = 's';
	describe = "Separator middle";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[5]){"one", "two", "three", "four", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "onetwothreefours";
	c = 's';
	describe = "Separator end";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[2]){"onetwothreefour", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "sonestwosthreesfourssfivessssssssssssssixs";
	c = 's';
	describe = "Separator everywhere";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[7]){"one", "two", "three", "four", "five", "ix", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "onetwo";
	c = 0;
	describe = "Empty separator";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[2]){"onetwo", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
	c = 'i';
	describe = "Long Lorem";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[26]){"lorem ", "psum dolor s", "t amet, consectetur ad", "p", "sc", "ng el", "t. Sed non r", "sus. Suspend", "sse lectus tortor, d", "gn", "ss", "m s", "t amet, ad", "p", "sc", "ng nec, ultr", "c", "es sed, dolor. Cras elementum ultr", "c", "es d" ,"am. Maecenas l", "gula massa, var", "us a, semper congue, eu", "smod non, m", ".", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "ssss";
	c = 's';
	describe = "Only separators";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[1]){NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);

	s = "toto ssss";
	c = 's';
	describe = "One word many separators";
	ptn_result = ft_split(s, c);
	if (check_ft_split((char*[2]){"toto ", NULL}, ptn_result))
	{
		(*sucess)++;
		//display_result(s, c, ptn_result, describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(s, c, ptn_result, describe, 0);
	}
	free_result(ptn_result);
}
