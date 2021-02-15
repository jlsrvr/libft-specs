#include "libft.h"
#include <stdio.h>

static void add_one_test(void *content)
{
	(*(int*)content)++;
}

static void put_to_zero_test(void *content)
{
	*(int*)content = 0;
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

static int check_ft_lstiter(t_list *lst, int *expected_result)
{
	int rindex;

	rindex = 0;
	while(lst)
	{
		if(*((int*)(lst->content)) != expected_result[rindex++])
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	free_result(t_list *elem)
{
	t_list *tmp;

	while (elem)
	{
		tmp = elem;
		elem = tmp->next;
		free(tmp);
	}
}

static void test_ft_lstiter(char *describe, int *depart, void (*f)(void *), int *exp_results, int *success, int *failure)
{
	t_list *first;
	int		dindex;

	first = ft_lstnew(depart);
	for (dindex = 1; dindex < 6; dindex++)
		ft_lstadd_back(&first, ft_lstnew(&depart[dindex]));

	ft_lstiter(first, f);
	if (check_ft_lstiter(first, exp_results))
	{
		(*success)++;
		//display_result(describe, first, exp_results, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, first, exp_results, 0);
	}
	free_result(first);
}

void specs_ft_lstiter(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);

	int depart[6] = {1, 2, 3, 4, 5, 6};
	int expected[6] = {2, 3, 4, 5, 6, 7};

	test_ft_lstiter("Add 1 to each content", depart, &add_one_test, expected, success, failure);
	int expected2[6] = {0, 0, 0, 0, 0, 0};
	test_ft_lstiter("Put to zero", depart, &put_to_zero_test, expected2, success, failure);
	test_ft_lstiter("Pointer function goes to NULL", depart, NULL, expected2, success, failure);
	test_ft_lstiter("List points to NULL", depart, &put_to_zero_test, expected2, success, failure);
}
