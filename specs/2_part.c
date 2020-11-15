#include <stdio.h>

void specs_ft_substr(int *succes, int*failure);
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
}
