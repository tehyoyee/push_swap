/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:27:58 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:27:59 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = b->head;
	ft_putstr("pa\n");
	if (b->head != b->head->next)
	{
		b->head = b->head->next;
		b->head->prev = tmp->prev;
		(b->head->prev)->next = b->head;
	}
	else
		b->head = NULL;
	if (!a->head)
	{
		a->head = tmp;
		a->head->next = tmp;
		a->head->prev = tmp;
		return ;
	}
	tmp->next = a->head;
	tmp->prev = a->head->prev;
	(a->head->prev)->next = tmp;
	a->head->prev = tmp;
	a->head = tmp;
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->head;
	ft_putstr("pb\n");
	if (a->head != a->head->next)
	{
		a->head = a->head->next;
		a->head->prev = tmp->prev;
		(a->head->prev)->next = a->head;
	}
	else
		a->head = NULL;
	if (!b->head)
	{
		b->head = tmp;
		b->head->next = tmp;
		b->head->prev = tmp;
		return ;
	}
	tmp->next = b->head;
	tmp->prev = b->head->prev;
	(b->head->prev)->next = tmp;
	b->head->prev = tmp;
	b->head = tmp;
}
