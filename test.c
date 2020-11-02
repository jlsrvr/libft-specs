#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str);


int main(int ac, char **av)
{
	int index;

	(void)ac;
	(void)av;

	// -----------------------FT_STRLEN--------------------------

	printf("Tests ft_strlen\n");

	char strs[5][15] = {"Jean", "", " ", "adore vraiment", "\n"} ;
	int expected;
	int result;

	for(index = 0; index < 5; index++)
	{
		expected = strlen(strs[index]);
		result = ft_strlen(strs[index]);
		if (expected == result)
		{
			printf("\033[1;32m");
			printf("OK for string = \"%s\"\n", strs[index]);
			printf("\033[0m");
		}
		else
		{
			printf("\033[0;31m--------------\n");
			printf("KO! for string = \"%s\"\n\n", strs[index]);
			printf("\033[1;32mExpected = %d\n",  expected);
			printf("\033[0;31mGot = %d\n\n",  result);
			printf("\033[0m");
		}
	}


	return (0);
}
