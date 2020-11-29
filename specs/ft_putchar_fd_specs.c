#include "../libft.h"
#include <stdio.h>

void specs_ft_putchar_fd(int *sucess, int *failure)
{
	printf("Tests for %s\n", &__func__[6]);
	char c;
	(void)sucess;
	(void)failure;

	for(c = 32; c <= 90; c += 3)
		ft_putchar_fd(c, 1);
	printf("==");
	for(c = 32; c <= 90; c += 3)
		printf("%c", c);
	printf("\n");
}
