#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
//	if (b->head == NULL)
//		return ;
//	ft_nodeadd_front(&a->head, ft_nodenew(b->head->value));
//	ft_nodedel(&b->head);
	printf("pa\n");
	t_node	*tmp;

	tmp = b->head;
	b->head = b->head->next;
	b->head->prev = NULL;
	if (!a->head)
	{
		a->head = tmp;
		a->head->next = NULL;
		a->head->prev = NULL;
		return ;
	}
	tmp->next = a->head;
	a->head->prev = tmp;
	a->head = tmp;
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	printf("pb\n");
	tmp = a->head;
	a->head = a->head->next;
	a->head->prev = NULL;
	if (!b->head)
	{
		b->head = tmp;
		b->head->next = NULL;
		b->head->prev = NULL;
		return ;
	}
	tmp->next = b->head;
	b->head->prev = tmp;
	b->head = tmp;
}

void	op_ra(t_stack *a)
{
	t_node	*tmp;

	if (!a->head || !a->head->next)
		return ;
	tmp = a->head;
	a->head = a->head->next;
	a->head->prev = NULL;
	tmp->prev = ft_nodelast(a->head);
	ft_nodelast(a->head)->next = tmp;
	tmp->next = NULL;
	printf("ra\n");
}

void	op_rb(t_stack *b)
{
	t_node	*tmp;

	if (!b->head || !b->head->next)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	b->head->prev = NULL;
	tmp->prev = ft_nodelast(b->head);
	ft_nodelast(b->head)->next = tmp;
	tmp->next = NULL;
	printf("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	op_ra(a);
	op_rb(b);
}