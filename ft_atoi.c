//HEADER

int ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && *str)
	{
		result = result * 10 + (*str - 48);
		++str;
	}
	return (sign * result);
}
