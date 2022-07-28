#include "push_swap.h"

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
