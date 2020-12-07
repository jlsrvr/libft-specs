#include "../libft.h"
#include <stdio.h>
#include <string.h>

static void display_result(const void *src, unsigned char c, size_t n, void *dest_result, void *dest_expected, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK! ") : printf("\033[0;31mKO! ");
	printf("for src = \"%s\" with char = %c and size = %zu\n\n", src, c, n);
	printf("Expected = %s\n",  dest_expected);
	printf("Got = %s\n\n",  dest_result);
	printf("\033[0m");
}

static int check_memccpy(void *ptn_expected, void *ptn_result, void *ft_call, void *actual_call)
{
	if (((actual_call == NULL ) == (ft_call == NULL)) && !strcmp(ptn_expected, ptn_result))
		return (1);
	return (0);
}


static	void test_ft_memccpy(const void *src, void *dest_expected, void *dest_result, size_t n, int c, int *success, int *failure)
{

	if (check_memccpy(dest_expected, dest_result, ft_memccpy(dest_result, src, c, n), memccpy(dest_expected, src, c, n)))
	{
		(*success)++;
		//display_result(src, (unsigned char)c, n, dest_result, dest_expected, 1);

	}
	else
	{
		(*failure)++;
		display_result(src, (unsigned char)c, n, dest_result, dest_expected, 0);
	}
}

void specs_ft_memccpy(void)
{
	printf("\nTests for %s\n", &__func__[6]);

	int success;
	int failure;
	size_t n;
	int c;
	success = 0;
	failure = 0;
	// NULL in either string will segfault
	const char src[16] = "adore\nvra\timent";
	char dest_expected[25] = "J'ai un tab \"\t\" de 21";
	char dest_result[25] = "J'ai un tab \"\t\" de 21";
	n = 16;
	c = 'e';
	test_ft_memccpy(src, dest_expected, dest_result, n, c, &success, &failure);
	char dest_expected1[25] = "J'ai un tab \"\t\" de 21";
	char dest_result1[25] = "J'ai un tab \"\t\" de 21";
	n = 15;
	c = 'x';
	test_ft_memccpy(src, dest_expected1, dest_result1, n, c, &success, &failure);
	char dest_expected2[25] = "J'ai un tab \"\t\" de 21";
	char dest_result2[25] = "J'ai un tab \"\t\" de 21";
	n = 15;
	c = -127;
	test_ft_memccpy(src, dest_expected2, dest_result2, n, c, &success, &failure);
	char dest_expected3[25] = "J'ai un tab \"\t\" de 21";
	char dest_result3[25] = "J'ai un tab \"\t\" de 21";
	n = 0;
	c = -127;
	test_ft_memccpy(src, dest_expected3, dest_result3, n, c, &success, &failure);
	char src1[5];
	src1[0] = 'a';
	src1[1] = 'b';
	src1[2] = 'c';
	src1[3] = -127;
	src1[4] = 0;
	char dest_expected4[25] = "J'ai un tab \"\t\" de 21";
	char dest_result4[25] = "J'ai un tab \"\t\" de 21";
	n = 5;
	c = -127;
	test_ft_memccpy(src1, dest_expected4, dest_result4, n, c, &success, &failure);
	const char src2[3] = "12";
	char dest_expected5[6] = "34567";
	char dest_result5[6] = "34567";
	n = 5;
	c = 0;
	test_ft_memccpy(src2, dest_expected5, dest_result5, n, c, &success, &failure);
	printf("\t%d success out of %d tests\n", success, (success + failure));
}
