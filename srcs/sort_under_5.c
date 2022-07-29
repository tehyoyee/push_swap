/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:07 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:08 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_2(t_stack *a)
{
	if (a->head->order > (a->head->next)->order)
		op_sa(*a);
}

void	sort_case_3(t_stack *a, size_t order_max)
{	
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
		if (a->head->order > (a->head->next)->order)
			op_sa(*a);
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
	sort_case_3(a, get_order_max(a->head, 3));
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
		sort_case_3(a, get_order_max(a->head, 3));
	else if (node_size == 4)
		sort_case_4(a, b, node_size);
	else
	{
		sort_case_5(a, b, node_size);
		op_pb(a, b);
		sort_case_3(a, get_order_max(a->head, 3));
		op_pa(a, b);
		op_pa(a, b);
	}
}
