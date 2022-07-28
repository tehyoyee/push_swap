#include "push_swap.h"

void	for_small(t_stack *a, t_stack *b, t_range *range)
{
	op_pb(a, b);
	range->small++;
}

void	for_middle(t_stack *a, t_stack *b, t_range *range)
{
	op_pb(a, b);
	op_rb(b);
	range->small++;
}

void	for_big(t_stack *a)
{
	op_ra(a);
}

void	push_a_to_b(t_stack *a, t_stack *b)
{
	t_range	range;
	size_t	node_cnt;

	node_cnt = node_count(a->head);
	range.small = 0;
	range.big = 0.000000053 * node_cnt * node_cnt + 0.03 * node_cnt + 14.5;
	while (a->head)
	{
		if (a->head->order < range.small)
		{
			for_small(a, b, &range);
		}
		else if (range.small <= a->head->order && \
			a->head->order < range.small + range.big)
		{
			for_middle(a, b, &range);
		}
		else
			for_big(a);
	}
}

void	push_b_to_a(t_stack *a, t_stack *b)
{
	size_t	cnt_pos;
	size_t	cnt;

	while (b->head)
	{
		cnt = node_count(b->head) - 1;
		cnt_pos = get_order_pos(b->head, cnt + 1, cnt);
		if (cnt_pos <= (cnt + 1) / 2)
		{
			while (b->head->order != cnt)
				op_rb(b);
			op_pa(a, b);
		}
		else
		{
			while (b->head->order != cnt)
				op_rrb(b);
			op_pa(a, b);
		}
	}
}
