/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:20 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:21 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a, int print)
{
	if (!a->head || !a->head->next)
		return ;
	a->head = a->head->prev;
	if (print == 1)
		ft_putstr("rra\n");
}

void	op_rrb(t_stack *b, int print)
{
	if (!b->head || !b->head->next)
		return ;
	b->head = b->head->prev;
	if (print == 1)
		ft_putstr("rrb\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	ft_putstr("rrr\n");
	op_ra(a, 0);
	op_rb(b, 0);
}
