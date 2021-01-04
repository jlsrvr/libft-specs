#include "../libft.h"
#include <stdio.h>

static void *add_one_test(void *content)
{
	int temp;

	temp = *(int*)content + 1;
	content = malloc(sizeof(temp) * 1);
	*(int*)content = temp;
	return (content);
}

static void *put_to_zero_test(void *content)
{
	if (*(int*)content % 2)
	{
		return (add_one_test(content));
	}
	return (NULL);
}

static void del(void *content)
{
	free(content);
}

static void delb(void *content)
{
	(void)content;
}

static void display_result(char *describe, t_list *lst, int *start, int *copy, int success)
{
	int rindex;

	printf("--------------\n");
	printf("%s\n", describe);
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	rindex = 0;
	if (start)
	{
		printf("Original values: ");
		while (rindex < 5)
			printf("%d, ", copy[rindex++]);
		printf("%d.\n", copy[rindex]);
		rindex = 0;
		printf("Original list: ");
		while (rindex < 5)
			printf("%d, ", start[rindex++]);
		printf("%d.\n", start[rindex]);
		rindex = 0;
	}
	while (lst)
	{
		printf("%d. ", rindex++);
		if (!((int*)lst->content))
			printf("Got = %s\n", lst->content);
		else
			printf("Got = %d\n", *(int*)lst->content);
		lst = lst->next;
	}
	printf("\033[0m");
}

static int check_ft_lstmap(t_list *og_lst, t_list *new_lst, void *(*f)(void*), int *depart)
{
	int index;

	index = 0;
	if ((!f && !new_lst) || (!depart && !new_lst))
		return (1);
	if ((og_lst == new_lst) || (ft_lstsize(og_lst) != ft_lstsize(new_lst)))
		return (0);
	while(new_lst)
	{
		if(*(int*)og_lst->content != depart[index++])
			return (0);
		if(!((int*)f(og_lst->content)) && !((int*)new_lst->content))
		{
			new_lst = new_lst->next;
			og_lst = og_lst->next;
			continue ;
		}
		if(*(int*)f(og_lst->content) != *(int*)new_lst->content)
			return (0);
		new_lst = new_lst->next;
		og_lst = og_lst->next;
	}
	return (1);
}

static void test_ft_lstmap(char *describe, int *copy, int *depart, void *(*f)(void *), int *success, int *failure)
{
	t_list *og_lst;
	t_list *new_lst;
	int		dindex;

	if (depart)
	{
		og_lst = ft_lstnew(depart);
		for (dindex = 1; dindex < 6; dindex++)
			ft_lstadd_back(&og_lst, ft_lstnew(&depart[dindex]));
	}
	else
		og_lst = NULL;
	new_lst = ft_lstmap(og_lst, f, &del);
	if (check_ft_lstmap(og_lst, new_lst, f, copy))
	{
		(*success)++;
		//display_result(describe, new_lst, depart, copy, 1);
	}
	else
	{
		(*failure)++;
		display_result(describe, new_lst, depart, copy, 0);
	}
	ft_lstclear(&og_lst, &delb);
	ft_lstclear(&new_lst, &del);
}

void specs_ft_lstmap(int *success, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);

	int depart[6] = {1, 2, 3, 4, 5, 6};
	int copy[6] = {1, 2, 3, 4, 5, 6};

	test_ft_lstmap("Add 1 to each content", depart, copy, &add_one_test, success, failure);
	test_ft_lstmap("Put to zero", depart, copy, &put_to_zero_test, success, failure);
	test_ft_lstmap("Function pointer goes to NULL", depart, copy, NULL, success, failure);
	test_ft_lstmap("List points to NULL", NULL, NULL, &put_to_zero_test, success, failure);
}
