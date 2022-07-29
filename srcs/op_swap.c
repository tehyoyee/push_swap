/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:29:00 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:29:01 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_value_sizet(size_t *a, size_t *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	op_sa(t_stack a, int print)
{
	if (a.head != NULL)
	{
		swap_value(&(a.head)->value, &((a.head)->next)->value);
		swap_value_sizet(&(a.head)->order, &((a.head)->next)->order);
	}
	if (print == 1)
		ft_putstr("sa\n");
}

void	op_sb(t_stack b, int print)
{
	if (b.head != NULL)
	{
		swap_value(&(b.head)->value, &((b.head)->next)->value);
		swap_value_sizet(&(b.head)->order, &((b.head)->next)->order);
	}
	if (print == 1)
		ft_putstr("sb\n");
}

void	op_ss(t_stack a, t_stack b)
{
	if (!a.head || !b.head)
		return ;
	op_sa(a, 0);
	op_sb(b, 0);
	ft_putstr("ss\n");
}
