#include "libft.h"
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

static void test_ft_lstdelone(char *describe, t_list *to_del, void (*del)(void*), int *success, int *failure)
{
	g_freed_content = to_del && del ? 0 : 1;
	ft_lstdelone(to_del, del);
	if (g_freed_content == 1)
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

void specs_ft_lstdelone(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	t_list *to_del;
	t_list *new;

	to_del = ft_lstnew(ft_strdup("Toto"));
	test_ft_lstdelone("Deleting a single element from a len 1 list", to_del, &test_del_f, success, failure);
	to_del = ft_lstnew(ft_strdup("Titi"));
	test_ft_lstdelone("When delete function pointer is NULL", to_del, NULL, success, failure);
	ft_lstdelone(to_del, &free);
	to_del = ft_lstnew(ft_strdup("Tete"));
	new = ft_lstnew(ft_strdup("Tata"));
	ft_lstadd_back(&to_del, new);
	test_ft_lstdelone("Deleting a single element from a len 2 list", to_del, &test_del_f, success, failure);
	ft_lstdelone(new, &free);
	test_ft_lstdelone("When list pointer is NULL", NULL, &test_del_f,success, failure);
	test_ft_lstdelone("When delete function and list pointer are NULL", NULL, NULL, success, failure);
}
