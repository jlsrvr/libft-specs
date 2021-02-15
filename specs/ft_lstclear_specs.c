#include "../srcs/libft.h"
#include <stdio.h>

static int g_freed_content;

static void test_del_f(void *content)
{
	free(content);
	g_freed_content += 1;
}

static void display_result(char *describe, int success)
{
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("\033[0m");
}

static	void add_n_to_back(t_list *first, int n)
{
	int size;

	for (size = 0 ; size < n; size++)
		ft_lstadd_back(&first, ft_lstnew(ft_strdup(ft_itoa(size))));
}

static void test_ft_lstclear(char *describe, t_list **to_del, void (*del)(void*), int expected_result, int *success, int *failure)
{
	g_freed_content = 0;
	ft_lstclear(to_del, del);
	if (g_freed_content == expected_result && (to_del == NULL || *to_del == NULL))
	{
		(*success)++;
		//display_result(describe, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, 0);
	}
}

void specs_ft_lstclear(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	t_list *to_del;

	to_del = ft_lstnew(ft_strdup("first"));
	test_ft_lstclear("Clearing 1 element long list", &to_del, &test_del_f, 1, success, failure);
	to_del = ft_lstnew(ft_strdup("first"));
	add_n_to_back(to_del, 5);
	test_ft_lstclear("Clearing 6 element long list", &to_del, &test_del_f, 6, success, failure);
	to_del = ft_lstnew(ft_strdup("first"));
	add_n_to_back(to_del, 5);
	test_ft_lstclear("Clearing 5 element long list", &to_del->next, &test_del_f, 5, success, failure);
	to_del = NULL;
	test_ft_lstclear("When list pointer is NULL", &to_del, &test_del_f, 0, success, failure);
	test_ft_lstclear("When list pointer pointer is NULL", NULL, &test_del_f, 0, success, failure);
	test_ft_lstclear("When delete function and list pointer are NULL", NULL, NULL, 0, success, failure);
}
