#include "push_swap.h"

int	is_sign(char av)
{
	if (av == '+')
		return (1);
	else if (av == '-')
		return (-1);
	else
		return (0);
}

long int	extract_number(char *str, int *index)
{
	long int	num;

	num = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		num = num * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (num);
}

int	process_string(char *str, long int *nums, int n2)
{
	int			j;
	int			n;
	int			sign;
	long int	num;

	j = 0;
	n = 0;
	num = 0;
	while (str[j])
	{
		sign = 1;
		if ((str[j] < '0' || str[j] > '9') && str[j]
			!= '-' && str[j] != '+' && str[j] != ' ')
			return (INT_MIN);
		if (is_sign(str[j]) == 1 || is_sign(str[j]) == -1)
			sign = is_sign(str[j++]);
		num = extract_number(str, &j);
		if (n + 1 > n2)
			break ;
		nums[n++] = sign * num;
		while (str[j] == ' ')
			j++;
	}
	return (n);
}

int	ft_atoi(char **nptr, long int *nums, int n2)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (nptr[i])
	{
		n += process_string(nptr[i], nums + n, n2);
		if (n <= 0)
			return (0);
		i++;
	}
	return (1);
}