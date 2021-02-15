#include "libft.h"
#include <stdio.h>

void specs_ft_putendl_fd(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	(void)sucess;
	(void)failure;
	int index;
	char *strs[5];
	strs[4] = 0;
	strs[0] = "3";
	strs[1] = "qwertyuQWERTY@$'\\|";
	strs[2] = "";
	strs[3] = NULL;

	for(index = 0; strs[index]; index++)
	{
		ft_putendl_fd(strs[index], 1);
		printf("==");
		printf("%s with next line", strs[index]);
		printf("\n");
	}
}
