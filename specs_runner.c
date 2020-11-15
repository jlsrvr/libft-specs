void spec_first_part(void);
void spec_second_part(void);

int ft_atoi(char *str);
void (*parts[3])(void);

int main(int ac, char **av)
{
	parts[0] = spec_first_part;
	parts[1] = spec_second_part;
	parts[2] = 0;

	int selected;

	if (ac > 1)
	{
		selected = ( ft_atoi(av[1]) - 1);
		(*parts[selected])();
		return (0);
	}
	for (selected = 0; parts[selected]; selected++)
		(*parts[selected])();
	return (0);
}
