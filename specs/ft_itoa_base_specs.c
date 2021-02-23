#include "libft.h"
#include <stdio.h>
#include <string.h>

static void display_result(long int n, char *expected, char *result, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("For Integer [%lu]\n", n);
	printf("Expected = \"%s\"\n", expected);
	printf("Result	 = \"%s\"\n\n", result);
	printf("\033[0m");
}

static int check_ft_itoa_base(char *result, char *expected)
{
	if (strcmp(result, expected))
		return (0);
	return (1);
}

static void run_tests(char *base, char **expected, int *sucess, int *failure)
{
	long int	my_int;
	int			index;
	char		*ptn_result;
	long int	ints[10] = {22147483647, 2147483647, -2147483648, -1, 0, 1 , 10, -10, 399, -59927};
	for(index = 0; index < 10; index++)
	{
		my_int = ints[index];
		ptn_result = ft_itoa_base(my_int, base);
		if (check_ft_itoa_base(ptn_result, expected[index]))
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

void specs_ft_itoa_base(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	char 	*base10 = "0123456789";
	char	*strs_base10[10] = {"22147483647", "2147483647", "-2147483648", "-1", "0", "1", "10", "-10", "399", "-59927"};
	char 	*basehexa = "0123456789ABCDEF";
	char 	*strs_hexa[10] = {"52817C7FF", "7FFFFFFF", "-80000000", "-1", "0", "1" , "A", "-A", "18F", "-EA17"};
	char 	*basebi = "01";
	char	*strs_bi[10] = {"10100101000000101111100011111111111", "1111111111111111111111111111111", "-10000000000000000000000000000000", "-1", "0", "1", "1010", "-1010", "110001111", "-1110101000010111"};
	char 	*baseoctal = "01234567";
	char	*strs_octal[10] = {"245005743777", "17777777777", "-20000000000", "-1", "0", "1", "12", "-12", "617", "-165027"};
	run_tests(base10, strs_base10, sucess, failure) ;
	run_tests(basehexa, strs_hexa, sucess, failure) ;
	run_tests(basebi, strs_bi, sucess, failure) ;
	run_tests(baseoctal, strs_octal, sucess, failure) ;
}
