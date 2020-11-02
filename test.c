#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ft_strlen(char *str);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
char *write_boolean(int value);

int main(int ac, char **av)
{
	int my_char;
	int expected;
	int result;
	int succes;
	int failure;
	char *chars;

	(void)ac;
	(void)av;

	// -----------------------FT_TOUPPER--------------------------

	printf("\nTests for ft_toupper\n");

	succes = 0;
	failure = 0;
	for(my_char = 0; my_char < 135; my_char++)
	{
		expected = toupper(my_char);
		result = ft_toupper(my_char);
		if (expected ==  result)
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for ascii char = \"%d\"\n\n", my_char);
			printf("\033[1;32mExpected = %d\n", my_char);
			printf("\033[0;31mGot = %d\n\n",  my_char);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ISPRINT--------------------------

	printf("\nTests for ft_isprint\n");

	succes = 0;
	failure = 0;
	for(my_char = -2; my_char < 135; my_char++)
	{
		expected = isprint(my_char);
		result = ft_isprint(my_char);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for ascii char = \"%d\"\n\n", my_char);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ISASCII--------------------------

	printf("\nTests for ft_isascii\n");

	succes = 0;
	failure = 0;
	for(my_char = -2; my_char < 135; my_char++)
	{
		expected = isascii(my_char);
		result = ft_isascii(my_char);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for ascii char = \"%d\"\n\n", my_char);
			printf("\033[1;32mExpected = %s\n", write_boolean(expected));
			printf("\033[0;31mGot = %s\n\n",  write_boolean(result));
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ISALNUM--------------------------

	printf("\nTests for ft_isalnum\n");

	chars = "J e\n/:0123456789AaZz@[`{";
	succes = 0;
	failure = 0;

	for(my_char = -2; my_char < 135; my_char++)
	{
		expected = isalnum(my_char);
		result = ft_isalnum(my_char);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", my_char);
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

	for(my_char = -2; my_char < 135; my_char++)
	{
		expected = isdigit(my_char);
		result = ft_isdigit(my_char);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", my_char);
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

	for(my_char = -2; my_char < 135; my_char++)
	{
		expected = isalpha(my_char);
		result = ft_isalpha(my_char);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for char = \"%c\"\n", my_char);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for char = \"%c\"\n\n", my_char);
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

	for(my_char = 0; my_char < 5; my_char++)
	{
		expected = strlen(strs[my_char]);
		result = ft_strlen(strs[my_char]);
		if ((expected && result) || (!expected && !result))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for string = \"%s\"\n", strs[my_char]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for string = \"%s\"\n\n", strs[my_char]);
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
