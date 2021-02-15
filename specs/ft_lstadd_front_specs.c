#include "../srcs/libft.h"
#include <stdio.h>

static void display_result(char *describe, t_list **result, t_list *new_elem, int success)
{
	t_list *elem;

	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	if (new_elem)
		printf("New elemement = [*content = \"%p\"]\n", new_elem->content);
	elem = *result;
	while (elem->next != NULL)
	{
		printf("[*content = \"%p\", ", elem->content);
		printf("*next = \"%p\"]\n", elem->next);
		elem = elem->next;
	}
	printf("[*content = \"%p\", ", elem->content);
	printf("*next = \"%p\"]\n", elem->next);
	printf("\033[0m");
}

static int check_ft_lstadd_front(t_list **alst, t_list *ptn_original_elem, t_list *new)
{
	if ((!new) && (*alst == ptn_original_elem))
		return (1);
	if (((*alst)->next == ptn_original_elem) && (*alst == new))
		return (1);
	return (0);
}

static void	free_result(t_list **result)
{
	t_list *elem;
	t_list *tmp;

	elem = *result;
	while (elem->next != NULL)
	{
		tmp = elem;
		elem = tmp->next;
		free(tmp);
	}
	free(elem);
}

static void test_ft_lstadd_front(char *describe, t_list **dest, t_list *new, int *success, int *failure)
{
	t_list *ptn_original_elem;

	ptn_original_elem = *dest;
	ft_lstadd_front(dest, new);
	if (check_ft_lstadd_front(dest, ptn_original_elem, new))
	{
		(*success)++;
		//display_result(describe, dest, new, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, dest, new, 0);
	}
	free_result(dest);
}

void specs_ft_lstadd_front(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	int new_int;
	int old_int;
	t_list *old;
	t_list *new;
	t_list **dest;

	old_int = 1;
	new_int = 2;
	old = ft_lstnew(&old_int);
	new = ft_lstnew(&new_int);
	dest = &old;
	test_ft_lstadd_front("Basic addition to front", dest, new, success, failure);
	old = ft_lstnew(&old_int);
	dest = &old;
	test_ft_lstadd_front("New is a pointer to NULL", dest, NULL, success, failure);
	old = NULL;
	new = ft_lstnew(&new_int);
	dest = &old;
	test_ft_lstadd_front("Adding new to NULL list", dest, new, success, failure);
}
