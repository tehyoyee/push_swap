#include "push_swap.h"


size_t	get_order_max(t_node *a, size_t node_size)
{
	size_t	i;
	size_t	max_pos;

	max_pos = 0;
	i = 0;
	while (i < node_size)
	{
		if (max_pos < a->order)
			max_pos = a->order;
		i++;
		a = a->next;
	}
	return max_pos;
}

size_t	get_order_pos(t_node *a, size_t node_size, size_t order)
{
	size_t	i;

	i = 0;
	while (i < node_size)
	{
		if (a->order == order)
			return (i);
		i++;
		a = a->next;
	}
	return (0);
}

void	sort_case_2(t_stack *a)
{
	if (a->head->order > (a->head->next)->order)
		op_sa(*a);
}

void	sort_case_3(t_stack *a)
{
	size_t	order_max;

	order_max = get_order_max(a->head, 3);
	if (a->head->order == order_max)
	{
		if ((a->head->next)->order < (a->head->prev)->order)
			op_ra(a);
		else
		{
			op_sa(*a);
			op_rra(a);
		}
	}
	else if ((a->head->next)->order == order_max)
	{
		if (a->head->order < (a->head->prev)->order)
		{
			op_sa(*a);
			op_ra(a);
		}
		else
			op_rra(a);
	}
	else if ((a->head->prev)->order == order_max)
	{
		if (a->head->order > (a->head->next)->order)
			op_sa(*a);
	}
}

void	sort_case_4(t_stack *a, t_stack *b, size_t node_size)
{
	size_t	order_min_pos;

	order_min_pos = get_order_pos(a->head, node_size, 0);
	if (order_min_pos <= 1)
	{
		while (a->head->order != 0)
			op_ra(a);
	}
	else
	{
		while (a->head->order != 0)
			op_rra(a);
	}
	op_pb(a, b);
	sort_case_3(a);
	op_pa(a, b);
}

void	sort_case_5(t_stack *a, t_stack *b, size_t node_size)
{
	size_t	order_min_pos;

	order_min_pos = get_order_pos(a->head, node_size, 0);
	if (order_min_pos <= 2)
	{
		while (a->head->order != 0)
			op_ra(a);
	}
	else
	{
		while (a->head->order != 0)
			op_rra(a);
	}
	op_pb(a, b);
	order_min_pos = get_order_pos(a->head, node_size, 1);
	if (order_min_pos <= 2)
	{
		while (a->head->order != 1)
			op_ra(a);
	}
	else
	{
		while (a->head->order != 1)
			op_rra(a);
	}
}

void	sort_under_5(t_stack *a, t_stack *b, size_t node_size)
{
	if (node_size == 2)
		sort_case_2(a);
	else if (node_size == 3)
		sort_case_3(a);
	else if (node_size == 4)
		sort_case_4(a, b, node_size);
	else
	{
		sort_case_5(a, b, node_size);
		op_pb(a, b);
		sort_case_3(a);
		op_pa(a, b);
		op_pa(a, b);
	}
}
