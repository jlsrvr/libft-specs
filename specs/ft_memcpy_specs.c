#include "../libft.h"
#include <stdio.h>
#include <string.h>

static int comp_null_begun_strings(void *str1, void *str2, int size)
{
	int index;

	if (str1 == NULL && str2 == NULL)
		return(1);
	index = -1;
	while (++index < size)
	{
		if (((char*)str1)[index] != ((char*)str2)[index])
			return (0);
	}
	return (1);
}

static void print_int_array(void *ptr, int size)
{
	int index;

	index = -1;
	while (++index < size)
		printf("%d, ", ((int*)ptr)[index]);
}

static void display_result(int my_char, void *dest_result, void *dest_expected, int string, int success)
{
	printf("--------------\n");
	(success) ? printf("\033[0;32mOK! ") : printf("\033[0;31mKO! ");
	if (string)
	{
		printf("with size = %d for string array = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
		printf("Expected = %s", dest_expected);
		printf("\n");
		printf("Got = %s", dest_result);
	}
	else
	{
		printf("with size = %d for int array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n\n", my_char);
		printf("Expected =");
		print_int_array(dest_expected, 10);
		printf("\n");
		printf("Got =");
		print_int_array(dest_result, 10);
	}
	printf("\n\n");
	printf("\033[0m");
}

static int check_memcpy(void *ptn_expected, void *ft_call, void *actual_call, size_t len)
{
	if (ptn_expected != ft_call)
		return(0);
	if (!(comp_null_begun_strings(ft_call, actual_call, len)))
		return (0);
	return (1);
}


static	void test_ft_memcpy(void *src, void *dest_expected, void *dest_result, size_t n, size_t step, int string, int *success, int *failure)
{
	size_t my_char;

	for(my_char = 0; my_char < n; my_char += step)
	{
		//      memcpy(dest_expected, src, my_char);
		//		ft_memcpy(dest_result, src,  my_char);
		if (check_memcpy(dest_result, ft_memcpy(dest_result, src,  my_char), memcpy(dest_expected, src,  my_char), my_char))
		{
			(*success)++;
		//	display_result(my_char, dest_result, dest_expected, string, 1);

		}
		else
		{
			(*failure)++;
			display_result(my_char, dest_result, dest_expected, string, 0);
		}
	}
}

void specs_ft_memcpy(void)
{
	printf("\nTests for %s\n", &__func__[6]);

	int success;
	int failure;
	success = 0;
	failure = 0;


	int src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int dest_expected[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int dest_result[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	test_ft_memcpy(src, dest_expected, dest_result, (4 * 10), 4, 0, &success, &failure);

	char src1[6] = "\t%1a";
	char dest_expected1[25] = "J'ai un tab \"\t\" de 21";
	char dest_result1[25] = "J'ai un tab \"\t\" de 21";
	//void *src, void *dest_expected, void *dest_result, size_t n, size_t step, int string, int *success, int *failure
	test_ft_memcpy(src1, dest_expected1, dest_result1, 6, 1, 1, &success, &failure);
	test_ft_memcpy(NULL, dest_expected1, dest_result1, 1, 1, 1, &success, &failure); // Should return dest
	test_ft_memcpy(src1, NULL, NULL, 1, 1, 1, &success, &failure); // Should return pointer NULL
	test_ft_memcpy(NULL, NULL, NULL, 3, 1, 1, &success, &failure); // Should return pointer NULL
	printf("\t%d success out of %d tests\n", success, (success + failure));
}
