#include <stdio.h>

void specs_ft_lstnew(int *success, int *failure);
void specs_ft_lstadd_front(int *success, int *failure);
void specs_ft_lstsize(int *success, int *failure);
void specs_ft_lstlast(int *success, int *failure);
void specs_ft_lstadd_back(int *success, int *failure);
void specs_ft_lstdelone(int *success, int *failure);
void specs_ft_lstiter(int *success, int *failure);

int		success;
int		failure;

static void	reset_counters(int *success, int *failure)
{
	*success = 0;
	*failure = 0;
}

static void print_results(int success, int failure)
{
	printf("\t%d success out of %d tests\n", success, (success + failure));
}

void spec_bonus_part(void)
{
	void (*specs[8])(int*, int*);
	int selected;

	success = 0;
	failure = 0;

	specs[0] = specs_ft_lstnew;
	specs[1] = specs_ft_lstadd_front;
	specs[2] = specs_ft_lstsize;
	specs[3] = specs_ft_lstlast;
	specs[4] = specs_ft_lstadd_back;
	specs[5] = specs_ft_lstdelone;
	specs[6] = specs_ft_lstiter;
	specs[7] = 0;

	for (selected = 0; specs[selected]; selected++)
	{
		(*specs[selected])(&success, &failure);
		print_results(success, failure);
		reset_counters(&success, &failure);
	}
}
