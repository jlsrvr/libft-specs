#include "../srcs/libft.h"
#include <stdio.h>

void specs_ft_putnbr_fd(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	(void)sucess;
	(void)failure;
	int index;
	int ints[5];
	ints[3] = 2147483647;
	ints[0] = -2147483648;
	ints[1] = -5;
	ints[2] = 1;
	ints[4] = 0;

	for(index = 0; ints[index]; index++)
	{
		ft_putnbr_fd(ints[index], 1);
		printf("==");
		printf("%d", ints[index]);
		printf("\n");
	}
}
