#include "../srcs/libft.h"
#include <stdio.h>
#include <ctype.h>

static char *write_boolean(int value)
{
	if (value == 0)
		return ("False");
	return ("True");
}

static void display_result(int my_char, int result, int expected, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK!") : printf("\033[0;31mKO!");
	printf("for ascii char = \"%d\"\n\n", my_char);
	printf("Expected = %s\n", write_boolean(expected));
	printf("Got = %s\n\n",  write_boolean(result));
	printf("\033[0m");
}

static int check_ascii(int expected, int result)
{
	if ((expected && result) || (!expected && !result))
		return (1);
	return (0);
}


static	void test_ascii_type(int (*og)(int), int (*ft)(int))
{
	int my_char;
	int expected;
	int result;
	int succes;
	int failure;

	succes = 0;
	failure = 0;
	for(my_char = 0; my_char < 135; my_char++)
	{
		expected = (*og)(my_char);
		result = (*ft)(my_char);
		if (check_ascii(expected, result))
		{
			succes++;
		//	display_result(my_char, expected, result, 1);
		}
		else
		{
			failure++;
			display_result(my_char, expected, result, 0);
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));
}

void specs_ascii_verification(void)
{
	// -----------------------FT_ISPRINT--------------------------

	printf("\nTests for ft_isprint\n");
	test_ascii_type(&isprint, &ft_isprint);

	// -----------------------FT_ISASCII--------------------------

	printf("\nTests for ft_isascii\n");
	test_ascii_type(&isascii, &ft_isascii);

	// -----------------------FT_ISALNUM--------------------------

	printf("\nTests for ft_isalnum\n");
	test_ascii_type(&isalnum, &ft_isalnum);

	// -----------------------FT_ISDIGIT--------------------------

	printf("\nTests for ft_isdigit\n");
	test_ascii_type(&isdigit, &ft_isdigit);

	// -----------------------FT_ISALPHA--------------------------

	printf("\nTests for ft_isalpha\n");
	test_ascii_type(&isalpha, &ft_isalpha);
}
