#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ft_strlen(char *str);
int ft_isalpha(int c);
char *write_boolean(int value);

int main(int ac, char **av)
{
	int index;
	int expected;
	int result;

	(void)ac;
	(void)av;

	// -----------------------FT_ISALPHA--------------------------

	printf("\nTests for ft_isalpha\n");

	chars = "J1 e\nAaZz@[`{";

	for(index = 0; chars[index]; index++)
	{
		expected = isalpha(chars[index]);
		result = ft_isalpha(chars[index]);
		if (expected == result)
		{
			printf("\033[1;32m");
			printf("OK for char = \"%c\"\n", chars[index]);
			printf("\033[0m");
		}
		else
		{
			printf("\033[0;31m--------------\n");
			printf("KO! for char = \"%c\"\n\n", chars[index]);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}

	// -----------------------FT_STRLEN--------------------------

	printf("\nTests for ft_strlen\n");

	char strs[5][15] = {"Jean", "", " ", "adore vraiment", "\n"} ;

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

char *write_boolean(int value)
{
	if (value == 0)
		return ("False");
	return ("True");
}
