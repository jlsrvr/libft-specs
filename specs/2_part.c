#include <stdio.h>

void specs_ft_substr(int *success, int *failure);
void specs_ft_strjoin(int *success, int *failure);
void specs_ft_strtrim(int *success, int *failure);
void specs_ft_split(int *success, int *failure);
void specs_ft_itoa(int *success, int *failure);
void specs_ft_strmapi(int *success, int *failure);

int		success;
int		failure;

void	reset_counters(int *success, int *failure)
{
	*success = 0;
	*failure = 0;
}

void print_results(int success, int failure)
{
	printf("\t%d success out of %d tests\n", success, (success + failure));
}

void spec_second_part(void)
{
	void (*specs[7])(int*, int*);
	int selected;

	success = 0;
	failure = 0;

	specs[0] = specs_ft_substr;
	specs[1] = specs_ft_strjoin;
	specs[2] = specs_ft_strtrim;
	specs[3] = specs_ft_split;
	specs[4] = specs_ft_itoa;
	specs[5] = specs_ft_strmapi;
	specs[6] = 0;

	for (selected = 0; specs[selected]; selected++)
	{
		(*specs[selected])(&success, &failure);
		print_results(success, failure);
		reset_counters(&success, &failure);
	}
}
