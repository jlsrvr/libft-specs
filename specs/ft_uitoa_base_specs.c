#include "libft.h"
#include <stdio.h>
#include <string.h>

static void display_result(t_uint_max n, char *expected, char *result, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("For Integer [%llu]\n", n);
	printf("Expected = \"%s\"\n", expected);
	printf("Result	 = \"%s\"\n\n", result);
	printf("\033[0m");
}

static int check_ft_uitoa_base(char *result, char *expected)
{
	if (strcmp(result, expected))
		return (0);
	return (1);
}

static void run_tests(char *base, char **expected, int *sucess, int *failure)
{
	t_uint_max	my_int;
	int			index;
	char		*ptn_result;
	t_uint_max	ints[6] = {22147483647, 2147483647, 0, 1 , 10, 399};
	for(index = 0; index < 6; index++)
	{
		my_int = ints[index];
		ptn_result = ft_uitoa_base(my_int, base);
		if (check_ft_uitoa_base(ptn_result, expected[index]))
		{
			(*sucess)++;
			//display_result(my_int, expected[index], ptn_result, 1);
		}
		else
		{
			(*failure)++;
			display_result(my_int, expected[index], ptn_result, 0);
		}
		free(ptn_result);
	}
}

void specs_ft_uitoa_base(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	char 	*base10 = "0123456789";
	char	*strs_base10[6] = {"22147483647", "2147483647", "0", "1", "10", "399"};
	char 	*basehexa = "0123456789ABCDEF";
	char 	*strs_hexa[6] = {"52817C7FF", "7FFFFFFF", "0", "1" , "A", "18F"};
	char 	*basebi = "01";
	char	*strs_bi[6] = {"10100101000000101111100011111111111", "1111111111111111111111111111111", "0", "1", "1010", "110001111"};
	char 	*baseoctal = "01234567";
	char	*strs_octal[6] = {"245005743777", "17777777777", "0", "1", "12", "617"};
	run_tests(base10, strs_base10, sucess, failure) ;
	run_tests(basehexa, strs_hexa, sucess, failure) ;
	run_tests(basebi, strs_bi, sucess, failure) ;
	run_tests(baseoctal, strs_octal, sucess, failure) ;
}
