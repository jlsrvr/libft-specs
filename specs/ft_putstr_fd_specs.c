#include "../libft.h"
#include <stdio.h>

void specs_ft_putstr_fd(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	(void)sucess;
	(void)failure;
	int index;
	char *strs[5];
	strs[4] = 0;
	strs[0] = "3";
	strs[1] = "qwertyuQWERTY\n\t  @$'\\|";
	strs[2] = "";
	strs[3] = NULL;

	for(index = 0; strs[index]; index++)
	{
		ft_putstr_fd(strs[index], 1);
		printf("==");
		printf("%s", strs[index]);
		printf("\n");
	}
}
