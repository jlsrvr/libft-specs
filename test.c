#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void *ft_memset(void *ptr, int value, size_t num);
void ft_bzero(void *ptr, size_t num);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strchr(const char *s, int c);
int ft_strlen(char *str);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
char *write_boolean(int value);
void print_null_begun_string(void *str, int size);
int comp_null_begun_strings(void *str1, void *str2, int size);
void test_ascii_change(int (*og)(int), int (*ft)(int));
void test_ascii_type(int (*og)(int), int (*ft)(int));

int main(int ac, char **av)
{
	int my_char;
	int expected;
	int result;
	int succes;
	int failure;
	char *ptn_expected;
	char *ptn_result;

	(void)ac;
	(void)av;

	// -----------------------FT_STRCHR--------------------------

	printf("\nTests for ft_strchr\n");

	succes = 0;
	failure = 0;
	char strchar[19] = "aAbBcCdD ZzXxYy\t%|";

		ptn_expected = strchr(strchar, '\0');
		ptn_result = ft_strchr(strchar, '\0');
		if (ptn_expected == ptn_result)
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
			printf("\033[0;31mKO! for ascii char = \"\\0\" in \"%s\" \n\n", strchar);
			printf("\033[1;32mExpected = %p\n", ptn_expected);
			printf("\033[0;31mGot = %p\n\n",  ptn_result);
			printf("\033[0m");
		}

	for(my_char = 0; my_char < 135; my_char++)
	{
		ptn_expected = strchr(strchar, my_char);
		ptn_result = ft_strchr(strchar, my_char);
		if (ptn_expected == ptn_result)
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
			printf("\033[0;31mKO! for ascii char = \"%c\" in \"%s\" \n\n", my_char, strchar);
			printf("\033[1;32mExpected = %p\n", ptn_expected);
			printf("\033[0;31mGot = %p\n\n",  ptn_result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCMP--------------------------

	printf("\nTests for ft_memcmp\n");

	int counter;
	succes = 0;
	failure = 0;

	expected = memcmp("a string", "whatever", 0);
	result = ft_memcmp("a string", "whatever", 0);
	if ( expected == result )
		succes++;
	else
	{
		failure++;
		printf("--------------\n");
		printf("\033[0;31mKO! comparing for \"a string\" with \"whatever\" up to 0\n\n");
		printf("\033[1;32mExpected = %d\n", expected);
		printf("\033[0;31mGot = %d\n\n", result);
		printf("\033[0m");
	}

	for(my_char = 0; my_char < 6; my_char++)
	{
		for(counter = 0; counter < 6; counter++)
		{
			char strs[6][10] = {"Tes\n34", " ", "tes", "123456789", ""};
			strs[5][0] = -12;

			expected = memcmp(strs[my_char], strs[my_char - counter], 15);
			result = ft_memcmp(strs[my_char], strs[my_char - counter], 15);
			if ( expected == result )
			{
				succes++;
				//printf("\033[1;32m");
				//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
				//printf("Expected = %s\n", str_expected);
				//printf("Got = %s\n\n",  str_result);
				//printf("\033[0m");
			}
			else
			{
				failure++;
				printf("--------------\n");
				printf("\033[0;31mKO! comparing for \"%s\" with \"%s\" up to 15\n\n", strs[my_char], strs[my_char - counter]);
				printf("\033[1;32mExpected = %d\n", expected);
				printf("\033[0;31mGot = %d\n\n", result);
				printf("\033[0m");
			}
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCHR--------------------------

	printf("\nTests for ft_memchr\n");

	succes = 0;
	failure = 0;

	ptn_expected = memchr("Nothing", '\n', 9);
	ptn_result = ft_memchr("Nothing", '\n', 9);
	if ( ptn_expected == ptn_result )
	{
		succes++;
		//printf("\033[1;32m");
		//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
		//printf("Expected = %s\n", str_expected);
		//printf("Got = %s\n\n",  str_result);
		//printf("\033[0m");
	}
	else
	{
		failure++;
		printf("--------------\n");
		printf("\033[0;31mKO! looking for \"\\n\" in string = \"Nothing\" up to 9\n\n");
		printf("\033[1;32mExpected = %p\n", ptn_expected);
		printf("\033[0;31mGot = %p\n\n", ptn_result);
	}
	for(my_char = 0; my_char < 6; my_char++)
	{
		char src[6] = "Tes\n34";

		ptn_expected = memchr(src, '\n', my_char);
		ptn_result = ft_memchr(src, '\n', my_char);
		if ( ptn_expected == ptn_result )
		{
			succes++;
			//printf("\033[1;32m");
			//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			//printf("Expected = %s\n", str_expected);
			//printf("Got = %s\n\n",  str_result);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! looking for \"\\n\" in string = \"%s\" up to %d\n\n", src, my_char);
			printf("\033[1;32mExpected = %p\n", ptn_expected);
			printf("\033[0;31mGot = %p\n\n", ptn_result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMMOVE--------------------------

	printf("\nTests for ft_memmove\n");

	succes = 0;
	failure = 0;

	char str[] = "foo-bar";
	char str2[] = "foo-bar";
	memmove(&str[3],&str[4],4);
	ft_memmove(&str2[3],&str2[4],4);
	if ( !strcmp(str, str2) )
		succes++;
	else
	{
		failure++;
		printf("--------------\n");
		printf("\033[0;31mKO! start with \"foo-bar\"\n");
		printf("\033[1;32mExpected = %s\n", str);
		printf("\033[0;31mGot = %s\n\n", str2);
		printf("\033[0m");
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCCPY--------------------------

	printf("\nTests for ft_memccpy\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 17; my_char++)
	{
		char src[] = "adore\nvra\timent";
		char dest_expected[25] = "J'ai un tab \"\t\" de 21";
		char dest_result[25] = "J'ai un tab \"\t\" de 21";

		ptn_expected = memccpy(dest_expected, src,'n', my_char);
		ptn_result = ft_memccpy(dest_result, src,'n', my_char);
		if ((ptn_expected == ptn_result) || !strcmp(ptn_expected, ptn_result))
			//{
			succes++;
		//printf("\033[1;32m");
		//printf("OK for string = \"%s\"\n", strs[my_char]);
		//printf("\033[0m");
		//}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for src = \"%s\" with char = n and size = %d\n\n", src, my_char);
			printf("\033[1;32mExpected = %s\n",  ptn_expected);
			printf("\033[0;31mGot = %s\n\n",  ptn_result);
			printf("\033[0m");
		}

		char src2[] = "adore\nvra\timent";
		char dest_expected2[20] = "J'ai";
		char dest_result2[20] = "J'ai";

		ptn_expected = memccpy(dest_expected2, src2,'n', my_char);
		ptn_result = ft_memccpy(dest_result2, src2,'n', my_char);
		if ((ptn_expected == ptn_result) || !strcmp(ptn_expected, ptn_result))
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
			printf("\033[0;31mKO! for src = \"%s\" with char = n and size = %d\n\n", src2, my_char);
			printf("\033[1;32mExpected = %s\n",  ptn_expected);
			printf("\033[0;31mGot = %s\n\n",  ptn_result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCPY--------------------------

	printf("\nTests for ft_memcpy with numbers\n");

	succes = 0;
	failure = 0;


	for(my_char = 0; my_char < 6; my_char++)
	{

		int src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int dest_expected[] ={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int dest_result[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

		memcpy(dest_expected, src, my_char);
		ft_memcpy(dest_result, src,  my_char);
		if ( comp_null_begun_strings(dest_expected, dest_result, 23) )
		{
			succes++;
			//printf("\033[1;32m");
			//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			//printf("Expected = %s\n", str_expected);
			//printf("Got = %s\n\n",  str_result);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			printf("\033[1;32mExpected =");
			print_null_begun_string(dest_expected, 23);
			printf("\n");
			printf("\033[0;31mGot =");
			print_null_begun_string(dest_result, 23);
			printf("\n\n");
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCPY--------------------------

	printf("\nTests for ft_memcpy\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 6; my_char++)
	{
		char src[5] = "\t%1a";
		char dest_expected[25] = "J'ai un tab \"\t\" de 21";
		char dest_result[25] = "J'ai un tab \"\t\" de 21";

		memcpy(dest_expected, src, my_char);
		ft_memcpy(dest_result, src,  my_char);
		if ( comp_null_begun_strings(dest_expected, dest_result, 23) )
		{
			succes++;
			//printf("\033[1;32m");
			//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			//printf("Expected = %s\n", str_expected);
			//printf("Got = %s\n\n",  str_result);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			printf("\033[1;32mExpected =");
			print_null_begun_string(dest_expected, 23);
			printf("\n");
			printf("\033[0;31mGot =");
			print_null_begun_string(dest_result, 23);
			printf("\n\n");
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_BZERO--------------------------

	printf("\nTests for ft_bzero\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 23; my_char++)
	{
		char str_expected[] = "J'ai un tab \"\t\" de 21";
		char str_result[] = "J'ai un tab \"\t\" de 21";

		bzero(str_expected, my_char);
		ft_bzero(str_result, my_char);
		if ( comp_null_begun_strings(str_expected, str_result, 23) )
		{
			succes++;
			//printf("\033[1;32m");
			//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			//printf("Expected = %s\n", str_expected);
			//printf("Got = %s\n\n",  str_result);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			printf("\033[1;32mExpected =");
			print_null_begun_string(str_expected, 23);
			printf("\n");
			printf("\033[0;31mGot =");
			print_null_begun_string(str_result, 23);
			printf("\n\n");
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMSET--------------------------

	printf("\nTests for ft_memset\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 23; my_char++)
	{
		char str_expected[] = "J'ai un tab \"\t\" de 21";
		char str_result[] = "J'ai un tab \"\t\" de 21";

		memset(str_expected, '&', my_char);
		ft_memset(str_result, '&', my_char);
		if ( strcmp(str_expected, str_result) == 0 )
		{
			succes++;
			//printf("\033[1;32m");
			//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			//printf("Expected = %s\n", str_expected);
			//printf("Got = %s\n\n",  str_result);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
			printf("\033[1;32mExpected = %s\n", str_expected);
			printf("\033[0;31mGot = %s\n\n",  str_result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_TOLOWER--------------------------

	printf("\nTests for ft_tolower\n");
	test_ascii_change(&tolower, &ft_tolower);

	// -----------------------FT_TOUPPER--------------------------

	printf("\nTests for ft_toupper\n");
	test_ascii_change(&toupper, &ft_toupper);

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

int comp_null_begun_strings(void *str1, void *str2, int size)
{
	int index;

	index = -1;
	while (++index < size)
	{
		if (((char*)str1)[index] != ((char*)str2)[index])
			return (0);
	}
	return (1);
}

void print_null_begun_string(void *ptr, int size)
{
	int index;

	index = -1;
	while (++index < size)
		printf("%c", ((char*)ptr)[index]);
}

char *write_boolean(int value)
{
	if (value == 0)
		return ("False");
	return ("True");
}

void test_ascii_type(int (*og)(int), int (*ft)(int))
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
}

void test_ascii_change(int (*og)(int), int (*ft)(int))
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
}
