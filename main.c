#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	a->head = NULL;
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
	ft_nodeprint(ft_nodelast(a.head));
}