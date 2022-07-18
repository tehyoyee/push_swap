#include "push_swap.h"

void	op_rra(t_stack *a)
{
	t_node	*last;
	t_node	*last_2nd;

	if (!a->head || !a->head->next)
		return ;
	last = ft_nodelast(a->head);
	last_2nd = last->prev;
	last_2nd->next = NULL;
	a->head->prev = last;
	last->prev = NULL;
	last->next = a->head;
	a->head = last;
	printf("rra\n");
}

void	op_rrb(t_stack *b)
{
	t_node	*last;
	t_node	*last_2nd;

	if (!b->head || !b->head->next)
		return ;
	last = ft_nodelast(b->head);
	last_2nd = last->prev;
	last_2nd->next = NULL;
	b->head->prev = last;
	last->prev = NULL;
	last->next = b->head;
	b->head = last;
	printf("rrb\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	printf("rrr\n");
	op_ra(a);
	op_rb(b);
}