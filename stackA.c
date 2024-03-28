#include "push_swap.h"

void	add_push(t_stack *new_node, int size, long int *arr, long int media)
{
	int		max;

	max = max_node(arr, size);
	if (new_node->val < media / 4)
		new_node->push = 1;
	else if (new_node->val < media / 3)
		new_node->push = 2;
	else if (new_node->val < media / 2)
		new_node->push = 3;
	else if (new_node->val < media / 1.5)
		new_node->push = 4;
	else if (new_node->val < max / 1.9)
		new_node->push = 5;
	else if (new_node->val < max / 1.7)
		new_node->push = 6;
	else if (new_node->val < max / 1.5)
		new_node->push = 7;
	else if (new_node->val < max / 1.3)
		new_node->push = 8;
	else if (new_node->val < max / 1.1)
		new_node->push = 9;
	else
		new_node->push = 10;
}

void	array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack		*new_node;
	int			i;
	long int	median;

	median = median_array(arr, size);
	i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			f(*stack);
		new_node->val = arr[i];
		if (size > 50)
			add_push(new_node, size, arr, median);
		else
			new_node->push = 0;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}