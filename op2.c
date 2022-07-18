#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	if (b->head == NULL)
		return ;
	ft_nodeadd_front(&a->head, ft_nodenew(b->head->value));
	ft_nodedel(&b->head);
	printf("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (a->head == NULL)
		return ;
	ft_nodeadd_front(&b->head, ft_nodenew(a->head->value));
	ft_nodedel(&a->head);
	printf("pb\n");
}

void	op_ra(t_stack *a)
{
	ft_nodeadd_back(&a->head, ft_nodenew(a->head->value));
	ft_nodedel(&a->head);
	printf("ra\n");
}

void	op_rb(t_stack *b)
{
	ft_nodeadd_back(&b->head, ft_nodenew(b->head->value));
	ft_nodedel(&b->head);
	printf("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	op_ra(a);
	op_rb(b);
}