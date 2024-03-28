#include "push_swap.h"

int	type_rot_b(t_stack **stack)
{
	t_stack	*temp;
	int		rot;
	int		rev;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	temp = *stack;
	rot = 0;
	rev = 0;
	while (temp)
	{
		if (temp->val == max(stack))
			break ;
		rot++;
		temp = temp->next;
	}
	rev = counter(*stack) - rot;
	if (rot <= rev)
		return (rot);
	else
		return (rev * -1);
}

void	rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = first;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *lst;
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *lst;
	second_last->next = NULL;
	*lst = last;
}

void	do_rrotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 4 && a && *a && (*a)->next)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (cod == 5 && b && *b && (*b)->next)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}

void	do_rotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 1 && a && *a && (*a)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (cod == 2 && b && *b && (*b)->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	else
		do_rrotate(a, b, cod);
}