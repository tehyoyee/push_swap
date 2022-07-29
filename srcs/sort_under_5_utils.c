/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:32 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:33 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (max_pos);
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
