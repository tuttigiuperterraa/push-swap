#include "push_swap.h"

void	pre_order(t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		if ((*a)->push == i)
			pb(b, a);
		else if (*b && (*b)->next && (*b)->val < (*b)->next->val)
			do_rotate(a, b, 3);
		else
			do_rotate(a, b, find_direction_push(*a, i));
		if (!check_push(a, i))
			i++;
	}
}

void	sort(t_stack **a, t_stack **b, int n)
{
	int	mediat;
	int	j;
	int	rot_a;

	if ((*a)->push != 0)
		pre_order(a, b);
	while (counter(*a) > 2 && n > 3)
	{
		mediat = median(a);
		if ((*a)->val < mediat)
			pb(b, a);
		else if (*b && (*b)->next && (*b)->val < (*b)->next->val)
			do_rotate(a, b, 3);
		else
			do_rotate(a, b, 1);
	}
	if ((*a)->val > (*a)->next->val && (counter(*a) == 2))
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	cont(a, b);
}

void	cont(t_stack **a, t_stack **b)
{
	if (counter(*a) == 3)
	{
		if ((max(a) == (*a)->next->val && (*a)->val < (*a)->next->next->val)
			|| max(a) == (*a)->val && (*a)->next->val > (*a)->next->next->val)
		{
			sa(a);
			write (1, "sa\n", 3);
		}
		if (max(a) == (*a)->val && (*a)->next->val < (*a)->next->next->val)
			do_rotate(a, b, 1);
		else if ((*a)->next->val > (*a)->val || max(a) == (*a)->next->val)
			do_rrotate(a, b, 4);
		else if (max(a) == (*a)->next->next->val && (*a)->val > (*a)->next->val)
		{
			sa(a);
			write (1, "sa\n", 3);
		}
	}
	else
	{
		little_check(a, b);
		if (b && *b)
			pa(a, b);
		free_stack(*b);
	}
}


int	is_sorted_list(t_stack *list)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->val > tmp->val))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

/*float	media_array(long array[], int lunghezza)
{
	float	media;
	int		i;
	int		somma;

	i = 0;
	if (lunghezza == 0)
		return (0);
	somma = 0;
	while (i < lunghezza)
		somma += array[i++];
	media = (float)somma / lunghezza;
	return (media);
}*/

int	main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;
	int			n;
	long int	*nums;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stackA = NULL;
	stackB = NULL;
	n = count_num(argv);
	if (n < 0)
		return (write(STDERR_FILENO, "Error\n", 6));
	nums = malloc(sizeof(long int ) * n);
	check_atoi(argv, nums, n);
	if (n == 1 || is_sorted(nums, n))
	{
		free(nums);
		return (0);
	}
	array_to_stack(nums, n, &stackA);
	sort(&stackA, &stackB, n);
	free_stack(stackA);
	free(nums);
	return (0);
}
