#include "push_swap.h"

t_node	*ft_nodelast(t_node *node)
{
	if (!node)
		return (NULL);
	while (node-> next)
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

void	ft_nodeprint(t_node *node)
{
	if (!node)
		return ;
	while (node)
	{
		printf("node->value : %d\n", node->value);
		node = node->next;
	}
}

void	ft_nodeprint_r(t_node *node)
{
	if (!node)
		return ;
	while (node)
	{
		printf("node->value : %d\n", node->value);
		node = node->prev;
	}
}
