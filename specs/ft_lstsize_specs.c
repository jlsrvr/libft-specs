#include "libft.h"
#include <stdio.h>

static void display_result(char *describe, t_list *list, int expected, int got, int success)
{
	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Expected size = %d\nGot size = %d for :\n", expected, got);
	while (list)
	{
		printf("[*content = \"%d\", ", *((int*)(list->content)));
		printf("*next = \"%p\"]\n", list->next);
		list = list->next;
	}
	printf("\033[0m");
}

static int check_ft_lstsize(int expected, int got)
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

static void test_ft_lstsize(char *describe, t_list *list, int expected, int *success, int *failure)
{
	int got;

	got = ft_lstsize(list);
	if (check_ft_lstsize(expected, got))
	{
		(*success)++;
	//	display_result(describe, list, expected, got, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, list, expected, got, 0);
	}
}

void specs_ft_lstsize(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int expected;
	t_list **list;
	t_list *first;

	first = NULL;
	list = &first;
	for(expected = 0; expected < 20; expected++)
	{
		test_ft_lstsize(ft_itoa(expected), *list, expected, success, failure);
		ft_lstadd_front(list, ft_lstnew(&expected));
	}
	free_result(*list);
}
