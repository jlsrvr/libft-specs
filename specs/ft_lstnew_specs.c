#include "../srcs/libft.h"
#include <stdio.h>

static void display_result(char *describe, void *content, t_list *result, int success)
{
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Expected content address= \"%p\"\n", content);
	printf("Result content address= \"%p\"\n", result->content);
	printf("Result next address= \"%p\"\n", result->next);
	printf("\033[0m");
}

static int check_ft_lstnew(t_list *result, void *content)
{
	if ((result->content == content) && (result->next == NULL))
		return (1);
	return (0);
}

static void	free_result(t_list *result)
{
	free(result);
}

static void test_ft_lstnew(char *describe, void *content, int *success, int *failure)
{
	t_list *result;

	result = ft_lstnew(content);
	if (check_ft_lstnew(result, content))
	{
		(*success)++;
		//display_result(describe, content, result, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, content, result, 0);
	}
	free_result(result);
}

void specs_ft_lstnew(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int my_int = 24;
	test_ft_lstnew("With an int pointer", &my_int, success, failure);
	char my_char = 'c';
	test_ft_lstnew("With a char pointer", &my_char, success, failure);
	char my_string[9] = "a string";
	test_ft_lstnew("With a string", my_string, success, failure);
	char *my_null = NULL;
	test_ft_lstnew("With a pointer to NULL", my_null, success, failure);
}
