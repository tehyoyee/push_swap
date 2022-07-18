#include "push_swap.h"

void	op_rra(t_stack *a)
{
	ft_nodeadd_front(&a->head, ft_nodenew(a->head->value));
	ft_nodedel(&a->head);
	printf("ra\n");
}

void	op_rrb(t_stack *b)
{
	ft_nodeadd_front(&b->head, ft_nodenew(b->head->value));
	ft_nodedel_bottom(&b->head);
	printf("rb\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	op_ra(a);
	op_rb(b);
}