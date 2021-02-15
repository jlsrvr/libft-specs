#include "libft.h"
#include <stdio.h>
#include <string.h>

static void display_result(char *expected, char *result, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK!\n") : printf("\033[0;31mKO!\n");
	printf("Expected = \"%s\"\n", expected);
	printf("Result = \"%s\"\n", result);
	printf("\033[0m");
}

static int check_ft_strnstr(char *expected, char *got, size_t len)
{
	if ((!expected && !got) || (!*expected && !*got))
		return (1);
	if (ft_strncmp(expected, got, len) == 0)
		return (1);
	return (0);
}

static void test_ft_strnstr(char *haystack, char *needle, size_t len, int *success, int *failure)
{
	char	*got;
	char  	*expected;

	got = ft_strnstr(haystack, needle, len);
	expected = strnstr(haystack, needle, len);
	if (check_ft_strnstr(expected, got, len))
	{
		(*success)++;
		//display_result(expected, got, 1);
	}
	else
	{
		(*failure)++;
		display_result(expected, got, 0);
	}

}


void specs_ft_strnstr(void)
{
	printf("\nTests for %s\n", &__func__[6]);
	int success;
	int failure;

	success = 0;
	failure = 0;
	char *haystack = "bonjojour";
	char *needle = "on ";
	char *needle2 = "jour";
	char *needle3 = "\0";
	char *needle4 = "uri";
	char *needle5 = "bon";
	char *needle7 = "Bon";
	char *needle6 = "ro";
	char *needle8 = "joj";
	char *needle9 = "bonjour";
	char *str12 = "Hello wwworld";
	char *o_find1 = "wworld";
	char *str21 = "FooBarBaz";
	char *o_find2 = "Baz";
	char *testn = "tetehelllotetahelloteshellotstetstesthello";
	char *needletestn = "test";
	char needleweird[2];
	needleweird[0] = -1;
	needleweird[1] = 0;
	char tofindweird[2];
	tofindweird[0] = 43;
	tofindweird[1] = 0;
	char *big = "123456789";
	char *little = "9";

	test_ft_strnstr(needleweird, tofindweird, 15, &success, &failure);
	test_ft_strnstr(haystack, needle, 15, &success, &failure);
	test_ft_strnstr(str12, o_find1, 15, &success, &failure);
	test_ft_strnstr(str21, o_find2, 15, &success, &failure);
	test_ft_strnstr(haystack, needle, 15, &success, &failure);
	test_ft_strnstr(haystack, needle2, 15, &success, &failure);
	test_ft_strnstr(haystack, needle3, 15, &success, &failure);
	test_ft_strnstr(haystack, needle4, 15, &success, &failure);
	test_ft_strnstr(haystack, needle5, 15, &success, &failure);
	test_ft_strnstr(haystack, needle6, 15, &success, &failure);
	test_ft_strnstr(haystack, needle7, 15, &success, &failure);
	test_ft_strnstr(haystack, needle8, 15, &success, &failure);
	test_ft_strnstr(haystack, needle9, 10, &success, &failure);
	test_ft_strnstr(needle3, needle4, 15, &success, &failure);
	test_ft_strnstr(needle3, needle3, 15, &success, &failure);
	test_ft_strnstr(testn, needletestn, 15, &success, &failure);
	test_ft_strnstr(haystack, haystack, 15, &success, &failure);
	test_ft_strnstr(haystack, "", 0, &success, &failure);
	test_ft_strnstr(haystack, "j", 0, &success, &failure);
	test_ft_strnstr(haystack, "j", 1, &success, &failure);
	test_ft_strnstr(haystack, "j", 2, &success, &failure);
	test_ft_strnstr(haystack, "j", 3, &success, &failure);
	test_ft_strnstr(big, little, 8, &success, &failure);
	test_ft_strnstr(haystack, needle5, 2, &success, &failure);

	printf("\t%d success out of %d tests\n", success, (success + failure));

}
