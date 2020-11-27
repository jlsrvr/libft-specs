#include <stdio.h>

void specs_ft_substr(int *succes, int*failure);
void specs_ft_strjoin(int *succes, int*failure);
void specs_ft_strtrim(int *succes, int*failure);
void specs_ft_split(int *succes, int*failure);
void specs_ft_itoa(int *succes, int*failure);

int		succes;
int		failure;

void	reset_counters(int *succes, int *failure)
{
	*succes = 0;
	*failure = 0;
}

void print_results(int succes, int failure)
{
	printf("\t%d success out of %d tests\n", succes, (succes + failure));
}

void spec_second_part(void)
{
	succes = 0;
	failure = 0;

	printf("\nTests for ft_substr\n");
	specs_ft_substr(&succes, &failure);
	print_results(succes, failure);

	reset_counters(&succes, &failure);
	printf("\nTests for ft_strjoin\n");
	specs_ft_strjoin(&succes, &failure);
	print_results(succes, failure);

	reset_counters(&succes, &failure);
	printf("\nTests for ft_strtrim\n");
	specs_ft_strtrim(&succes, &failure);
	print_results(succes, failure);

	reset_counters(&succes, &failure);
	printf("\nTests for ft_split\n");
	specs_ft_split(&succes, &failure);
	print_results(succes, failure);

	reset_counters(&succes, &failure);
	printf("\nTests for ft_itoa\n");
	specs_ft_itoa(&succes, &failure);
	print_results(succes, failure);
}
