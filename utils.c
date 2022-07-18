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

void	ft_nodeadd_front(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	*node = new;
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

void	ft_nodeprint(t_node *node1, t_node *node2)
{
	if (!node1)
		return ;
	printf("==========================\n");
	printf("==========================\n");
	printf("Stack A \n");
	while (node1)
	{
		printf("node->value : %d\n", node1->value);
		node1 = node1->next;
	}
	printf("Stack B \n");
	while (node2)
	{
		printf("node->value : %d\n", node2->value);
		node2 = node2->next;
	}
	printf("==========================\n");
	printf("==========================\n");
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

void	ft_nodedel(t_node **node)
{
	t_node	*temp;


	if (!node || !(*node))
		return ;
	temp = (*node)->next;
	(*node)->value = 0;
	free(*node);
	*node = NULL;
	if (temp)
		*node = temp;
}

void	ft_nodedel_bottom(t_node **node)
{
	t_node	*temp;

	temp = ft_nodelast(node);
	temp = (*node)->next;
	(*node)->value = 0;
	free(*node);
	*node = NULL;
	if (temp)
		*node = temp;
}
