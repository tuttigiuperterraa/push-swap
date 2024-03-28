#include "push_swap.h"

int	counter(t_stack *a)
{
	int		n;
	t_stack	*temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

void	f(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return ;
}

void	remove_first(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
}

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}