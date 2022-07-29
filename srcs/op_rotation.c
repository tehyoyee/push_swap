/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:41 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:42 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a)
{
	ft_putstr("ra\n");
	if (!a->head || !a->head->next)
		return ;
	a->head = a->head->next;
}

void	op_rb(t_stack *b)
{
	if (!b->head || !b->head->next)
		return ;
	b->head = b->head->next;
	ft_putstr("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	ft_putstr("rr\n");
	op_ra(a);
	op_rb(b);
}
