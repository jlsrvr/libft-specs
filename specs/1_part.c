#include "../libft.h"
#include <strings.h>
#include <ctype.h>
#include <malloc/malloc.h>
#include <stdio.h>

void		print_null_begun_string(void *str, int size);
int			comp_null_begun_strings(void *str1, void *str2, int size);
void		test_ascii_change(int (*og)(int), int (*ft)(int));
void		test_calloc(size_t count, size_t size, int *succes, int *failure);
void		specs_ascii_verification(void);
void		specs_ft_strnstr(void);
void		specs_ft_memcpy(void);
void		specs_ft_memccpy(void);

void spec_first_part(void)
{
	int		my_char;
	int		expected;
	int		result;
	int		succes;
	int		failure;
	int		counter;
	char	*ptn_expected;
	char	*ptn_result;
	void (*specs[5])(void);
	int selected;

	specs[0] = specs_ascii_verification;
	specs[1] = specs_ft_strnstr;
	specs[2] = specs_ft_memcpy;
	specs[3] = specs_ft_memccpy;
	specs[4] = 0;

	for (selected = 0; specs[selected]; selected++)
	{
		(*specs[selected])();
	}

	// -----------------------FT_CALLOC--------------------------

	printf("\nTests for ft_calloc\n");
	succes = 0;
	failure = 0;

	test_calloc(0, 2, &succes, &failure);
	test_calloc(1, 0, &succes, &failure);
	test_calloc(0, 0, &succes, &failure);
	test_calloc(19, 19, &succes, &failure);

	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRDUP--------------------------

	printf("\nTests for ft_strdup\n");

	char strssrc[5][15] = {"Jean", "", " ", "adore vraiment", "\n"} ;
	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 5; my_char++)
	{
		ptn_expected = strdup(strssrc[my_char]);
		ptn_result = ft_strdup(strssrc[my_char]);
		if ((ft_strlen(ptn_expected) == ft_strlen(ptn_result)) && !ft_strncmp(ptn_expected, ptn_result, 15))
		{
			succes++;
			//printf("\033[1;32m");
			//printf("OK for string = \"%s\"\n", strssrc[my_char]);
			//printf("\033[0m");
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for string = \"%s\"\n\n", strssrc[my_char]);
			printf("\033[1;32mExpected = %s\n",  ptn_expected);
			printf("\033[0;31mGot = %s\n\n",  ptn_result);
			printf("\033[0m");
		}
		free(ptn_expected);
		free(ptn_result);
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_ATOI--------------------------

	printf("\nTests for ft_atoi\n");

	char *intstrs[14] = {"0", "-2147483648", "2147483647", "1234ab567", " -1234 567", " \n\t1234ab567", " --+1234567", "&1234ab567", "+548", "+-2", "-+2", "++3", "+47+5", 0};
	succes = 0;
	failure = 0;

	for(my_char = 0; intstrs[my_char]; my_char++)
	{
		expected = atoi(intstrs[my_char]);
		result = ft_atoi(intstrs[my_char]);
		if (expected == result)
		{
			succes++;
			/*printf("OK! for string = \"%s\"\n\n", intstrs[my_char]);
				printf("\033[0;32mGot = %d\n\n",  result);
				printf("\033[0m");*/
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for string = \"%s\"\n\n", intstrs[my_char]);
			printf("\033[1;32mExpected = %d\n",  expected);
			printf("\033[0;31mGot = %d\n\n",  result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRLCAT--------------------------

	printf("\nTests for ft_strlcat\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 12; my_char++)
	{
		char *src = "MagiquE";
		char expected_dst[11] = "bS";
		char result_dst[11] = "bS";

		expected = (int)strlcat(expected_dst, src, (size_t)my_char);
		result = (int)ft_strlcat(result_dst, src, (size_t)my_char);
		if ((expected == result) && !strcmp(expected_dst, result_dst))
		{
			succes++;
			/*printf("\033[0;31mKO! for dstsize = \"%d\"\n\n", my_char);
				printf("\033[1;32mExpected = %d with \"%s\"\n", expected, expected_dst);
				printf("\033[0;31mGot = %d with \"%s\"\n\n",  result, result_dst);
				printf("\033[0m");*/
		}
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! for dstsize = \"%d\"\n\n", my_char);
			printf("\033[1;32mExpected = %d with \"%s\"\n", expected, expected_dst);
			printf("\033[0;31mGot = %d with \"%s\"\n\n",  result, result_dst);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRLCPY--------------------------

	printf("\nTests for ft_strlcpy\n");

	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 10; my_char++)
	{
		char *src = "MagiquE";
		char expected_dst[10] = "bS";
		char result_dst[10] = "bS";

		expected = (int)strlcpy(expected_dst, src, (size_t)my_char);
		result = (int)ft_strlcpy(result_dst, src, (size_t)my_char);
		if ((expected == result) && !strcmp(expected_dst, result_dst))
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
			printf("\033[0;31mKO! for dstsize = \"%d\"\n\n", my_char);
			printf("\033[1;32mExpected = %d with \"%s\"\n", expected, expected_dst);
			printf("\033[0;31mGot = %d with \"%s\"\n\n",  result, result_dst);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRNCMP--------------------------

	printf("\nTests for ft_strncmp\n");

	succes = 0;
	failure = 0;

	expected = strncmp("a string", "whatever", 0);
	result = ft_strncmp("a string", "whatever", 0);
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

			expected = strncmp(strs[my_char], strs[my_char - counter], 15);
			result = ft_strncmp(strs[my_char], strs[my_char - counter], 15);
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

	// -----------------------FT_STRRCHR--------------------------

	printf("\nTests for ft_strrchr\n");

	succes = 0;
	failure = 0;
	char strrchar[38] = "aAbBcCdD ZzXxYy\t%|aAbBcCdD ZzXxYy\t%|";

	ptn_expected = strrchr(strrchar, '\0');
	ptn_result = ft_strrchr(strrchar, '\0');
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
		printf("\033[0;31mKO! for ascii char = \"\\0\" in \"%s\" \n\n", strrchar);
		printf("\033[1;32mExpected = %p\n", ptn_expected);
		printf("\033[0;31mGot = %p\n\n",  ptn_result);
		printf("\033[0m");
	}

	for(my_char = 0; my_char < 135; my_char++)
	{
		ptn_expected = strrchr(strrchar, my_char);
		ptn_result = ft_strrchr(strrchar, my_char);
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
			printf("\033[0;31mKO! for ascii char = \"%c\" in \"%s\" \n\n", my_char, strrchar);
			printf("\033[1;32mExpected = %p\n", ptn_expected);
			printf("\033[0;31mGot = %p\n\n",  ptn_result);
			printf("\033[0m");
		}
	}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

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

	// -----------------------FT_STRLEN--------------------------

	printf("\nTests for ft_strlen\n");

	char strs[5][15] = {"Jean", "", " ", "adore vraiment", "\n"} ;
	succes = 0;
	failure = 0;

	for(my_char = 0; my_char < 5; my_char++)
	{
		expected = strlen(strs[my_char]);
		result = ft_strlen(strs[my_char]);
		if (expected == result)
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
		expected = 0; // no defined behaviour in this case for the actual strlen
		result = ft_strlen(NULL);
		if (expected == result)
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
			printf("\033[0;31mKO! for string = \"%s\"\n\n", NULL);
			printf("\033[1;32mExpected = %d\n",  expected);
			printf("\033[0;31mGot = %d\n\n",  result);
			printf("\033[0m");
		}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));
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

void test_calloc(size_t count, size_t size, int *succes, int *failure)
{
	void *ptn_expected = calloc(size, count);
	void *ptn_result = ft_calloc(size, count);
	if (((ptn_expected && ptn_result) || (ptn_result == ptn_expected)) && (malloc_size(ptn_expected) == malloc_size(ptn_result)))
	{
		(*succes)++;
		/*printf("OK! for count = %zu and size %zu\n\n", count, size);
		printf("\033[1;32mExpected = \"%zu\"\n", malloc_size(ptn_expected));
		printf("Got = \"%zu\"\n\n",  malloc_size(ptn_result));
		printf("\033[0m");*/
	}
	else
	{
		(*failure)++;
		printf("--------------\n");
		printf("\033[0;31mKO! for size = %zu and count %zu\n\n", size, count);
		printf("\033[1;32mExpected = \"%s\"\n",  ptn_expected);
		printf("\033[0;31mGot = \"%s\"\n\n",  ptn_result);
		printf("\033[0m");
	}
	free(ptn_expected);
	free(ptn_result);
}
