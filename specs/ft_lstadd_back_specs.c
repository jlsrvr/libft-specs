#include "libft.h"
#include <stdio.h>

static void display_result(char *describe, t_list *lst, t_list *last, t_list *original_last, t_list *new_elem, int success)
{
	int position;

	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	if (!new_elem)
		printf("Expected %p to be last :\n", original_last);
	else if(!original_last)
		printf("Expected %p to be last :\n", new_elem);
	else
		printf("Expected %p to be after %p :\n", new_elem, original_last);
	position = 1;
	while (lst)
	{
		printf("%d. \"%p\"\n", position++, lst);
		lst = lst->next;
	}
	printf("Got %p, after %p\n", last, original_last);
	printf("\033[0m");
}

static int check_ft_lstadd_back(t_list *last, t_list *ptn_original_last, t_list *new_elem)
{
	if ((!new_elem) && (last == ptn_original_last))
		return (1);
	if (last == new_elem)
		return (1);
	return (0);
}

static void	free_result(t_list **result)
{
	t_list *elem;
	t_list *tmp;

	elem = *result;
	while (elem)
	{
		tmp = elem;
		elem = tmp->next;
		free(tmp);
	}
}

static void test_ft_lstadd_back(char *describe, t_list **dest, t_list *new, int *success, int *failure)
{
	t_list *ptn_original_last;
	t_list *og_last_next;

	ptn_original_last = ft_lstlast(*dest);
	ft_lstadd_back(dest, new);
	og_last_next = (ptn_original_last && new) ? ptn_original_last->next : ft_lstlast(*dest);
	if (check_ft_lstadd_back(og_last_next, ptn_original_last, new))
	{
		(*success)++;
		//display_result(describe, *dest, og_last_next, ptn_original_last, new, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, *dest, og_last_next, ptn_original_last, new, 0);
	}
	free_result(dest);
}

void specs_ft_lstadd_back(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	t_list *old;
	t_list *new;
	t_list **dest;

	old = ft_lstnew(NULL);
	new = ft_lstnew(NULL);
	dest = &old;
	test_ft_lstadd_back("Basic addition to the end", dest, new, success, failure);
	old = ft_lstnew(NULL);
	dest = &old;
	test_ft_lstadd_back("New is a pointer to NULL", dest, NULL, success, failure);
	old = NULL;
	new = ft_lstnew(NULL);
	dest = &old;
	test_ft_lstadd_back("Adding new to NULL list", dest, new, success, failure);
	old = ft_lstnew(NULL);
	new = ft_lstnew(NULL);
	new->next = ft_lstnew(NULL);
	dest = &old;
	test_ft_lstadd_back("Adding a list to end", dest, new, success, failure);
}
