/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:28:51 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:28:52 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodelast(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_nodeadd_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!node || !new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	last = ft_nodelast(*node);
	last->next = new;
	new->prev = last;
	new->order = 0;
}

t_node	*ft_nodenew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	a->head = NULL;
	b->head = NULL;
	while (i < argc)
	{
		ft_nodeadd_back(&(a->head), ft_nodenew(ft_atoi(argv[i++])));
	}
	a->head->prev = ft_nodelast(a->head);
	a->head->order = 0;
	ft_nodelast(a->head)->next = a->head;
}

void	init_node_order(t_stack *a, int argc)
{
	t_node	*temp1;
	t_node	*temp2;
	int		i;
	int		j;

	i = 0;
	temp1 = a->head;
	temp2 = a->head;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc)
		{
			if (temp1->value > temp2->value)
			{
				temp1->order++;
			}
			j++;
			temp2 = temp2->next;
		}
		i++;
		temp1 = temp1->next;
	}
}
