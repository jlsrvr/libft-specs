#include "../libft.h"
#include <stdio.h>

static void display_result(int n, char *result, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Integer =  %d\n", n);
	printf("Result	= \"%s\"\n\n", result);
	printf("\033[0m");
}

static int check_ft_itoa(int n, char *result)
{
	int got;

	got = ft_atoi((const char*)result);
	if (n == got)
		return (1);
	return (0);
}

void specs_ft_itoa(int *sucess, int *failure)
{
	int		index;
	int		my_int;
	char	*ptn_result;
	int		ints[9] = { 2147483647, -2147483648, -1, 0, 1 , 10, -10, 399, -59927 };

	for(index = 0; index < 9; index++)
	{
		my_int = ints[index];
		ptn_result = ft_itoa(my_int);
		if (check_ft_itoa(my_int, ptn_result))
		{
			(*sucess)++;
			//display_result(my_int, ptn_result, 1);
		}
		else
		{
			(*failure)++;
			display_result(my_int, ptn_result, 0);
		}
		free(ptn_result);
	}
}
