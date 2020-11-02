#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ft_strlen(char *str);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
char *write_boolean(int value);

int main(int ac, char **av)
{
	int index;
	int expected;
	int result;
	int succes;
	int failure;
	char *chars;

	(void)ac;
	(void)av;

	// -----------------------FT_ISALNUM--------------------------

	printf("\nTests for ft_isdigit\n");

	chars = "J e\n/:0123456789AaZz@[`{";
	succes = 0;
	failure = 0;
	for(index = 0; chars[index]; index++)
	{
		expected = isalnum(chars[index]);
		result = ft_isalnum(chars[index]);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", chars[index]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", chars[index]);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ISDIGIT--------------------------

	printf("\nTests for ft_isdigit\n");

	chars = "J e\n/:0123456789";
	succes = 0;
	failure = 0;

	for(index = 0; chars[index]; index++)
	{
		expected = isdigit(chars[index]);
		result = ft_isdigit(chars[index]);
		if (expected == result)
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", chars[index]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", chars[index]);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ISALPHA--------------------------

	printf("\nTests for ft_isalpha\n");

	chars = "J1 e\nAaZz@[`{";
	succes = 0;
	failure = 0;

	for(index = 0; chars[index]; index++)
	{
		expected = isalpha(chars[index]);
		result = ft_isalpha(chars[index]);
		if (expected == result)
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", chars[index]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", chars[index]);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRLEN--------------------------

	printf("\nTests for ft_strlen\n");

	char strs[5][15] = {"Jean", "", " ", "adore vraiment", "\n"} ;
	succes = 0;
	failure = 0;

	for(index = 0; index < 5; index++)
	{
		expected = strlen(strs[index]);
		result = ft_strlen(strs[index]);
		if (expected == result)
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for string = \"%s\"\n", strs[index]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for string = \"%s\"\n\n", strs[index]);
			printf("\033[1;32mExpected = %d\n",  expected);
			printf("\033[0;31mGot = %d\n\n",  result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));


	return (0);
}

char *write_boolean(int value)
{
	if (value == 0)
		return ("False");
	return ("True");
}
