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
}

void	sort(t_stack *a, t_stack *b)
{
	a->head
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 3)
		sort_case2(ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (argc == 4)
		sort_case3(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	init_stack(&a, &b, argc, argv);
	op_pb();
	sort(&a, &b);
	ft_nodeprint(a.head, b.head);
	ft_nodeprint_r(a.head, b.head);
}