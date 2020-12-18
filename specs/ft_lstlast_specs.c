#include "../libft.h"
#include <stdio.h>

static void display_result(char *describe, t_list *list, t_list *expected, t_list *got, int success)
{
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Last element is at address = %p\nGot address = %p for :\n", expected, got);
	while (list)
	{
		printf("At \"%p\" we have ", list);
		printf("[*content = \"%p\", ", list->content);
		printf("*next = \"%p\"]\n", list->next);
		list = list->next;
	}
	printf("\033[0m");
}

static int check_ft_lstlast(t_list *expected, t_list *got)
{
	if (expected == got)
		return (1);
	return (0);
}

static void	free_result(t_list *list_item)
{
	t_list *tmp;

	if (!list_item)
		return ;
	while (list_item)
	{
		tmp = list_item;
		list_item = tmp->next;
		free(tmp);
	}
}

static void test_ft_lstlast(char *describe, t_list *list, t_list *expected, int *success, int *failure)
{
	t_list *got;

	got = ft_lstlast(list);
	if (check_ft_lstlast(expected, got))
	{
		(*success)++;
		//display_result(describe, list, expected, got, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, list, expected, got, 0);
	}
}

void specs_ft_lstlast(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int size;
	t_list *expected;
	t_list *first;
	t_list **list;

	first = ft_lstnew(NULL);
	expected = first;
	test_ft_lstlast("One item in the list", first, expected, success, failure);
	free_result(first);
	first = ft_lstnew(NULL);
	expected = ft_lstnew(NULL);
	first->next = expected;
	test_ft_lstlast("Two items in the list", first, expected, success, failure);
	free_result(first);
	expected = NULL;
	test_ft_lstlast("NULL pointer given instead of list", NULL, expected, success, failure);
	first = ft_lstnew(NULL);
	expected = first;
	list = &first;
	for(size = 0; size < 100; size++)
		ft_lstadd_front(list, ft_lstnew(&size));
	test_ft_lstlast("Much longer list is given", *list, expected, success, failure);
	free_result(*list);
}
