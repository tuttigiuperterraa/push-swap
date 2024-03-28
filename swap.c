#include "push_swap.h"

void	sa(t_stack **a)
{
	int	t;

	if (!a || !*a || !(*a)->next)
		return ;
	t = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = t;
}

void	sb(t_stack **a)
{
	int	t;

	if (!a || !*a || !(*a)->next)
		return ;
	t = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = t;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}