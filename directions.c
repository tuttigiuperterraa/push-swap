#include "push_swap.h"

int	find_direction_med(t_stack *a, int med)
{
	int	pi;
	int	pj;

	pi = penality_r(a, med);
	pj = penality_rr(a, med);
	if (pj < pi)
		return (4);
	else
		return (1);
}

int	find_direction_push(t_stack *a, int push)
{
	int	pi;
	int	pj;

	pi = penality_r_push(a, push);
	pj = penality_rr_push(a, push);
	if (pj < pi)
		return (4);
	else
		return (1);
}
