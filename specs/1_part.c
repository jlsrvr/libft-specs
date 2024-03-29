#include "libft.h"
#include <strings.h>
#include <ctype.h>
#if SYSTEM == macos
# include <malloc/malloc.h>
# define MALLOC_SIZE(x) malloc_size(x)
#else
# include <bsd/string.h>
# include <malloc.h>
# define MALLOC_SIZE(x) malloc_usable_size(x)
#endif
#include <stdio.h>

void		print_null_begun_string(void *str, int size);
int			comp_null_begun_strings(void *str1, void *str2, int size);
void		test_ascii_change(int (*og)(int), int (*ft)(int));
void		test_calloc(size_t count, size_t size, int *succes, int *failure);
void		test_strncmp(char *str1, char *str2, size_t len, int *succes, int *failure);
void		test_strcmp(char *str1, char *str2, int *succes, int *failure);
void		test_memcmp(void *str1, void *str2, size_t len, int *succes, int *failure);
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
	test_calloc(3, 1, &succes, &failure);
	test_calloc(500, sizeof(int), &succes, &failure);
	test_calloc(0, 0, &succes, &failure);
	test_calloc(1, 1, &succes, &failure);
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
		char *srclcpy = "MagiquE";
		char *expected_dst = NULL;
		char *result_dst = NULL;

		result = (int)ft_strlcpy(result_dst, srclcpy, (size_t)1);
		if ((0 == result) && (expected_dst == NULL))
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
			printf("\033[0;31mKO! for dstsize = \"%d\"\n\n", 1);
			printf("\033[1;32mExpected = %d with \"%s\"\n", 0, NULL);
			printf("\033[0;31mGot = %d with \"%s\"\n\n",  result, result_dst);
			printf("\033[0m");
		}
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRNCMP--------------------------

	printf("\nTests for ft_strncmp\n");

	succes = 0;
	failure = 0;
	char *string = "a string";
	char *wateva = "whatever";
	char *vide = "";
	test_strncmp(string, wateva , 0, &succes, &failure);
	test_strncmp(string, wateva , 1, &succes, &failure);
	test_strncmp(string, wateva , 16, &succes, &failure);
	test_strncmp(vide, "whatever" , 5, &succes, &failure);
	test_strncmp(vide, vide , 1, &succes, &failure);
	test_strncmp("   ", vide , 5, &succes, &failure);
	test_strncmp("   ", "   " , 5, &succes, &failure);
	test_strncmp("\t", "yeh" , 5, &succes, &failure);
	char str_test_ncmp[3];
	str_test_ncmp[0] = 'c';
	str_test_ncmp[1] = -12;
	str_test_ncmp[2] = 0;
	test_strncmp("\t", str_test_ncmp , 5, &succes, &failure);
	test_strncmp(str_test_ncmp, str_test_ncmp , 5, &succes, &failure);
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRCMP--------------------------

	printf("\nTests for ft_strcmp\n");

	succes = 0;
	failure = 0;
	char *stringcmp = "a string";
	char *watevacmp = "whatever";
	char *videcmp = "";
	test_strcmp(stringcmp, watevacmp, &succes, &failure);
	test_strcmp(videcmp, "whatever", &succes, &failure);
	test_strcmp(videcmp, videcmp, &succes, &failure);
	test_strcmp("   ", videcmp, &succes, &failure);
	test_strcmp("   ", "   ", &succes, &failure);
	test_strcmp("\t", "yeh", &succes, &failure);
	char str_test_cmp[3];
	str_test_cmp[0] = 'c';
	str_test_cmp[1] = -12;
	str_test_cmp[2] = 0;
	test_strcmp("\t", str_test_cmp, &succes, &failure);
	test_strcmp(str_test_cmp, str_test_cmp, &succes, &failure);
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_STRRCHR--------------------------

	printf("\nTests for ft_strrchr\n");

	succes = 0;
	failure = 0;
	char strrchar[38] = "aAbBcCdD ZzXxYy\t%|AbBcCdD ZzXxYy\t%|";

	ptn_expected = strrchr(strrchar, 0);
	ptn_result = ft_strrchr(strrchar, 0);
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

	char strrchar1[1] = "";

	ptn_expected = strrchr(strrchar1, '\0');
	ptn_result = ft_strrchr(strrchar1, '\0');
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
		printf("\033[0;31mKO! for ascii char = \"\\0\" in \"%s\" \n\n", strrchar1);
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

	test_memcmp(string, wateva , 0, &succes, &failure);
	test_memcmp(string, wateva , 1, &succes, &failure);
	test_memcmp(string, wateva , 8, &succes, &failure);
	test_memcmp(vide, "whatever" , 1, &succes, &failure);
	test_memcmp(vide, vide , 1, &succes, &failure);
	test_memcmp("   ", vide, 1, &succes, &failure);
	test_memcmp("   ", "   " , 2, &succes, &failure);
	test_memcmp("\t", "yeh" , 1, &succes, &failure);
	char str_test_memcmp[3];
	str_test_memcmp[0] = 'c';
	str_test_memcmp[1] = -12;
	str_test_memcmp[2] = 0;
	test_memcmp("\t", str_test_memcmp , 1, &succes, &failure);
	test_memcmp(str_test_memcmp, str_test_memcmp , 2, &succes, &failure);
	printf("\t%d success out of %d tests\n", succes, (succes + failure));

	// -----------------------FT_MEMCHR--------------------------

	printf("\nTests for ft_memchr\n");

	succes = 0;
	failure = 0;
	char *nothing = "Nothing";
	ptn_expected = memchr(nothing, '\n', 8);
	ptn_result = ft_memchr(nothing, '\n', 8);
	if ( ptn_expected == ptn_result )
	{
		succes++;
		//printf("\033[1;32m");
		//printf("0K! with size = %d for string = \"J'ai un tab \"\t\" de 21\"\n\n", my_char);
		//printf("\033[1;32mExpected = %p\n", ptn_expected);
		//printf("\033[0;31mGot = %p\n\n", ptn_result);
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
	int count;
	count = 0;
	size_t len;

	for(len = 0; len < 7; len++)
	{
		char src[8] = "foo-bar";
		char *dest;
		char src1[8] = "foo-bar";
		char *dest1;

		dest = src + 1;
		dest1 = src1 + 1;
		memmove(dest1, src1, len);
		if ((dest == ft_memmove(dest, src, len)) && !strcmp(dest, dest1))
			succes++;
		else
		{
			failure++;
			printf("--------------\n");
			printf("\033[0;31mKO! start with \"foo-bar\"\n");
			printf("\033[1;32mExpected = %s\n", dest1);
			printf("\033[0;31mGot = %s\n\n", dest);
			printf("\033[0m");
		}
	}
	char *src2 = NULL;
	char *dest2 = NULL;

	if ((dest2 == ft_memmove(dest2, src2, len)) && (dest2 == NULL))
		succes++;
	else
	{
		failure++;
		printf("--------------\n");
		printf("\033[0;31mKO! NULL and NULL with len positive\n");
		printf("\033[1;32mExpected = NULL\n");
		printf("\033[0;31mGot = %s\n\n", dest2);
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
		if (comp_null_begun_strings(str_expected, str_result, my_char))
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

	for(my_char = 0; my_char < 22; my_char++)
	{
		char str_expected[22] = "J'ai un tab \"\t\" de 21";
		char str_result[22] = "J'ai un tab \"\t\" de 21";

		memset(str_expected, '&', my_char);
		ft_memset(str_result, '&', my_char);
		if (strcmp(str_expected, str_result) == 0)
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
	/*expected = 0; // no defined behaviour in this case for the actual strlen
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
	}*/
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
	void *ptn_expected = calloc(count, size);
	void *ptn_result = ft_calloc(count, size);
	if (((ptn_expected && ptn_result) || (ptn_result == ptn_expected)) && (MALLOC_SIZE(ptn_expected) == MALLOC_SIZE(ptn_result)) && !memcmp(ptn_expected, ptn_result, count*size))
	{
		(*succes)++;
		/*printf("OK! for count = %zu and size %zu\n\n", count, size);
		  printf("\033[1;32mExpected = \"%zu\"\n", MALLOC_SIZE(ptn_expected));
		  printf("Got = \"%zu\"\n\n",  MALLOC_SIZE(ptn_result));
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

void test_strncmp(char *str1, char *str2 , size_t len, int *succes, int *failure)
{
	int		expected;
	int		result;

	expected = strncmp(str1, str2, len);
	result = ft_strncmp(str1, str2, len);
	if ( expected == result )
	{
		(*succes)++;
		/*printf("\033[1;32m");
		printf("OK! comparing for \"%s\" with \"%s\" up to %zu\n\n", str1, str2, len);
		printf("Expected = %d\n", expected);
		printf("Got = %d\n\n",  result);
		printf("\033[0m");*/
	}
	else
	{
		(*failure)++;
		printf("--------------\n");
		printf("\033[0;31mKO! comparing for \"%s\" with \"%s\" up to %zu\n\n", str1, str2, len);
		printf("\033[1;32mExpected = %d\n", expected);
		printf("\033[0;31mGot = %d\n\n", result);
		printf("\033[0m");
	}

}

void test_strcmp(char *str1, char *str2 , int *succes, int *failure)
{
	int		expected;
	int		result;

	expected = strcmp(str1, str2);
	result = ft_strcmp(str1, str2);
	if ( expected == result )
	{
		(*succes)++;
		/*printf("\033[1;32m");
		printf("OK! comparing for \"%s\" with \"%s\"\n\n", str1, str2);
		printf("Expected = %d\n", expected);
		printf("Got = %d\n\n",  result);
		printf("\033[0m");*/
	}
	else
	{
		(*failure)++;
		printf("--------------\n");
		printf("\033[0;31mKO! comparing for \"%s\" with \"%s\" \n\n", str1, str2);
		printf("\033[1;32mExpected = %d\n", expected);
		printf("\033[0;31mGot = %d\n\n", result);
		printf("\033[0m");
	}

}

void test_memcmp(void *str1, void *str2 , size_t len, int *succes, int *failure)
{
	int		expected;
	int		result;

	expected = memcmp(str1, str2, len);
	result = ft_memcmp(str1, str2, len);
	if ( expected == result )
	{
		(*succes)++;
		/*printf("\033[1;32m");
		printf("OK! comparing for \"%s\" with \"%s\" up to %zu\n\n", str1, str2, len);
		printf("Expected = %d\n", expected);
		printf("Got = %d\n\n",  result);
		printf("\033[0m");*/
	}
	else
	{
		(*failure)++;
		printf("--------------\n");
		printf("\033[0;31mKO! comparing for \"%s\" with \"%s\" up to %zu\n\n", str1, str2, len);
		printf("\033[1;32mExpected = %d\n", expected);
		printf("\033[0;31mGot = %d\n\n", result);
		printf("\033[0m");
	}

}
