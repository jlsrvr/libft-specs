#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void *ft_memset(void *ptr, int value, size_t num);
void ft_bzero(void *ptr, size_t num);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
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

	// -----------------------FT_MEMCCPY--------------------------

	printf("\nTests for ft_memccpy\n");

	char *ptn_expected;
	char *ptn_result;
	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 17; my_char++)
	{
		char src[] = "adore\nvra\timent";
		char dest_expected[] = "J'ai un tab \"\t\" de 21";
		char dest_result[] = "J'ai un tab \"\t\" de 21";

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

	printf("\nTests for ft_memcpy\n");

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
		char dest_expected[] = "J'ai un tab \"\t\" de 21";
		char dest_result[] = "J'ai un tab \"\t\" de 21";

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

	succes = 0;
	failure = 0;
	for(my_char = 0; my_char < 135; my_char++)
	{
		expected = tolower(my_char);
		result = ft_tolower(my_char);
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
