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
}

void	ft_nodeadd_front(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	*node = new;
	printf("sdf\n");

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

void	ft_nodeprint_r(t_node *node1, t_node *node2)
{
	if (!node1)
		return ;
	node1 = ft_nodelast(node1);
	printf("==================================\n");
	printf("========= R Stack A ============\n");
	printf("==================================\n");
	while (node1)
	{
		printf("node->value : %d\n", node1->value);
		node1 = node1->prev;
	}
	printf("==================================\n");
	printf("==================================\n");
	node2 = ft_nodelast(node2);
	if (!node2)
		return ;
	printf("==================================\n");
	printf("========= R Stack B ============\n");
	printf("==================================\n");
	while (node2)
	{
		printf("node->value : %d\n", node2->value);
		node2 = node2->prev;
	}
	printf("==================================\n");
	printf("==================================\n");
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
	*node = temp;
	(*node)->prev = NULL;
}

void	ft_nodedel_bottom(t_node **node)
{
	t_node	*temp;

	temp = ft_nodelast(*node);
	if (!node || !(*node))
		return ;
	(*node) = (*node)->prev;
	(*node)->next = NULL;
	(temp)->value = 0;
	free(temp);
	temp = NULL;
}

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
