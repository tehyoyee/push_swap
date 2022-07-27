#include "push_swap.h"


int	find_insert_index(t_node *a, t_node *b, int node_size)
{
	int	result;

	result = 0;
	while (b->value > a->value && result < node_size)
	{
		b = b->next;
		result++;
	}
	return (result);
}


int	find_max(t_node *node)
{
	int	i;
	int j;
	int	result[3];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	i = 0;
	j = node_count(node);
	while (i < j)
	{
		if (result[0] < node->value)
		{
			result[0] = node->value;
		}
		node = node->next;
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (result[1] < node->value && node->value != result[0])
		{
			result[1] = node->value;
		}
		node = node->next;
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (result[2] < node->value && node->value != result[0] && node->value != result[1])
		{
			result[2] = node->value;
		}
		node = node->next;
		i++;
	}
	return (result[2]);
}

void	sort_stack_a(t_stack *a)
{
	int	arr[3];

	arr[0] = a->head->value;
	a->head = a->head->next;
	arr[1] = a->head->value;
	a->head = a->head->next;
	arr[2] = a->head->value;
	a->head = a->head->next;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		return ;
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
	{
		op_sa(*a);
		op_ra(a);
	}
	if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		op_sa(*a);
	if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		op_rra(a);
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		op_ra(a);
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		op_sa(*a);
		op_rra(a);
	}
	
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = find_max(a->head);
	while (a->head->value >= max)
		op_ra(a);
	op_pb(a, b);
	while(node_count(a->head) != 3)
	{
		i = 0;
		if (a->head->value >= max)
		{
			op_ra(a);
			i++;
			continue;
		}
		j = find_insert_index(a->head, b->head, node_count(b->head));
		while (i < j)
		{
			op_rb(b);
			i++;
		}
		while ((b->head->prev)->value < a->head->value && a->head->value - (b->head->prev)->value < a->head->value - b->head->value)
			op_rrb(b);
		i = 0;
		op_pb(a, b);
	}
	while (b->head->prev->value > b->head->value)
		op_rrb(b);
	sort_stack_a(a);
	while (node_count(b->head) != 0)
		op_pa(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	check_split(&argc, argv);
	check_decimal(argc, argv);
	check_reduplicate(argc, argv);
	if (argc == 3)
		sort_case2(ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (argc == 4)
		sort_case3(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	init_stack(&a, &b, argc, argv);
	init_node_order(&a, argc);
	ft_nodeprint(a.head, b.head);
	// sort(&a, &b); 
	// ft_nodeprint(a.head, b.head);
	// ft_nodeprint_r(a.head, b.head);
}