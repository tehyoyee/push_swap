#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	a->head = NULL;
	b->head = NULL;
	while (i < argc)
	{
		ft_nodeadd_back(&a->head, ft_nodenew(atoi(argv[i++])));
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b, argc, argv);
	// ft_nodeprint(a.head);
	// op_sa(a);
	// ft_nodeprint(a.head, b.head);
	// op_pb(&a,&b);
	// ft_nodeprint(a.head, b.head);
	op_pb(&a,&b);
	op_pb(&a,&b);
	op_pb(&a,&b);
	ft_nodeprint(a.head, b.head);
	op_pb(&a,&b);
	ft_nodeprint(a.head, b.head);
	op_ra(&a);
	// ft_nodedel(&a.head);
	ft_nodeprint(a.head, b.head);
	op_rb(&b);
	// ft_nodeadd_front(&b.head, ft_nodenew(3));
	// ft_nodeadd_front(&b.head, ft_nodenew(4));
	ft_nodeprint(a.head, b.head);
	op_rr(&a, &b);
	ft_nodeprint(a.head, b.head);
	// ft_nodeprint(ft_nodelast(a.head));
}