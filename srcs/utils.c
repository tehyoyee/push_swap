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
