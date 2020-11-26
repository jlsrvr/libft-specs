#include "../libft.h"
#include <stdio.h>

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

static	int	len_array(char **array)
{
	int count;

	count = 0;
	while (array[count])
		count++;
	return(count);
}

static int  count_words(char const *s, char c)
{
  size_t counter;
  size_t index;

  counter = 0;
  index = 0;
  while (s[index])
  {
    while (s[index] == c)
      index++;
    if (index > 0 && s[index] && s[index - 1] == c)
      counter++;
    if (s[index])
      index++;
  }
  if (counter == 0 && s[index - 1] == c)
    return(counter);
  if (s[0] != c)
    counter++;
  return (counter);
}

static int check_ft_split(char const *s, char c, char **result)
{
	int i;
	size_t len_s;

	len_s = ft_strlen(s);
 	if (count_words(s, c) != len_array(result))
		return (0);
	for (i = 0; result[i]; i++)
	{
		if((ft_strnstr(s, result[i], len_s)) && (ft_strchr(result[i], c)) && (c != 0))
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
	char const *s;
	char c;
	char **ptn_result;
	char *describe;

	s = NULL;
	c = 's';
	describe = "Null string";
	ptn_result = ft_split(s, c);
	if (*ptn_result == NULL)
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
	if (*ptn_result == NULL)
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
	if (check_ft_split(s, c, ptn_result))
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
	if (check_ft_split(s, c, ptn_result))
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
	if (check_ft_split(s, c, ptn_result))
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
	if (check_ft_split(s, c, ptn_result))
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
	if (check_ft_split(s, c, ptn_result))
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

	s = "sonestwosthreesfour";
	c = 0;
	describe = "Empty separator";
	ptn_result = ft_split(s, c);
	if (check_ft_split(s, c, ptn_result))
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
	if (check_ft_split(s, c, ptn_result))
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
