#include "../libft.h"
#include <stdio.h>

ICI LES FONCTIONS DOIVENT RENVOYER UN POINTEUR SU OBJET VOID
static void add_one_test(void *content)
{
	(*(int*)content)++;
}

static void put_to_zero_test(void *content)
{
	*(int*)content = 0;
}

static void del(void *content)
{
	free(content);
}

static void display_result(char *describe, t_list *lst, int *expected_result, int success)
{
	int rindex;

	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	rindex = 0;
	while (lst)
	{
		printf("%d. ", rindex);
		printf("Expecting \"%d\", got = \"%d\"\n", expected_result[rindex++], *((int*)(lst->content)));
		lst = lst->next;
	}
	printf("\033[0m");
}

static int check_ft_lstmap(t_list *og_lst, t_list *new_lst, int *expected_result)
{
	int rindex;

	rindex = 0;
	if ((og_lst == new_lst) || (ft_lstsize(og_lst) != ft_lstsize(new_lst)))
		return (0);
	while(new_lst)
	{
		if(*((int*)(new_lst->content)) != expected_result[rindex++])
			return (0);
		new_lst = new_lst->next;
	}
	return (1);
}

static void test_ft_lstmap(char *describe, int *depart, void (*f)(void *), int *exp_results, int *success, int *failure)
{
	t_list *og_lst;
	int		dindex;

	og_lst = ft_lstnew(depart);
	for (dindex = 1; dindex < 6; dindex++)
		ft_lstadd_back(&og_lst, ft_lstnew(&depart[dindex]));

	new_lst = ft_lstmap(first, f, &del);
	if (check_ft_lstmap(og_lst, new_lst, exp_results))
	{
		(*success)++;
		display_result(describe, first, exp_results, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, first, exp_results, 0);
	}
	ft_lstclear(&first, free);
}

void specs_ft_lstmap(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);

	int depart[6] = {1, 2, 3, 4, 5, 6};
	int expected[6] = {2, 3, 4, 5, 6, 7};

	test_ft_lstmap("Add 1 to each content", depart, &add_one_test, expected, success, failure);
	int expected2[6] = {0, 0, 0, 0, 0, 0};
	test_ft_lstmap("Put to zero", depart, &put_to_zero_test, expected2, success, failure);
	test_ft_lstmap("Pointer function goes to NULL", depart, NULL, expected2, success, failure);
	test_ft_lstmap("List points to NULL", depart, &put_to_zero_test, expected2, success, failure);
}
