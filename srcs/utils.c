/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:46 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:48 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		result++;
		s++;
	}
	return (result);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

size_t	node_count(t_node *node)
{
	size_t		result;
	t_node		*tmp;

	if (!node)
		return (0);
	result = 1;
	tmp = node;
	node = node->next;
	while (node != tmp)
	{
		result++;
		node = node->next;
	}
	return (result);
}
