#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	a->head = NULL;
	b->head = NULL;
	while (i < argc)
	{
		ft_nodeadd_back(&(a->head), ft_nodenew(atoi(argv[i++])));
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b, argc, argv);
	op_pb(&a,&b);
	op_pb(&a,&b);
	op_pb(&a,&b);
	op_rra(&a);
	op_rrb(&b);
	ft_nodeprint(a.head, b.head);
	ft_nodeprint_r(a.head, b.head);

}