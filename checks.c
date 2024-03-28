#include "push_swap.h"

/*int	check_input(char **nptr, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i <= n)
	{
		j = 0;
		while (nptr[i][j])
		{
			if ((nptr[i][j] < '0' || nptr[i][j] > '9') && nptr[i][j]
				!= '-' && nptr[i][j] != '+' && nptr[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}*/

int	ft_check(long int *nums, int i)
{
	int	j;

	i--;
	while (i >= 0)
	{
		j = 0;
		if (nums[i] > 2147483647 || nums[i] < -2147483648)
			return (0);
		while (j < i)
		{
			if ((int)nums[i] == (int)nums[j])
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

void	check_atoi(char **argv, long int *nums, int n)
{
	if (!ft_atoi(argv, nums, n) || ft_check(nums, n) == 0)
	{
		free(nums);
		write(STDERR_FILENO, "Error\n", 6);
		exit (0);
	}
}

int	is_sorted(long int *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_push(t_stack **a, int i)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->push == i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	little_check(t_stack **a, t_stack **b)
{
	int	i;
	int	rot_b;

	i = 0;
	if (!a || !(*a) || !b || !(*b))
		return ;
	if (!(*a)->next || !(*b)->next)
		return ;
	while (counter(*b) > 1)
	{
		rot_b = type_rot_b(b);
		if (rot_b <= 0)
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 5);
			pa(a, b);
		}
		else
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 2);
			pa(a, b);
		}
	}
}