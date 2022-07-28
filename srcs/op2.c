#include "push_swap.h"

void	head_free(t_stack *stack)
{
	stack->head->prev = NULL;
	stack->head->next = NULL;
	stack->head->value = 0;
	stack->head = NULL;
}

void	op_pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	ft_putstr("pa\n");
	tmp = b->head;
	if (b->head != b->head->next)
	{
		b->head = b->head->next;
		b->head->prev = tmp->prev;
		(b->head->prev)->next = b->head;
	}
	else
		b->head = NULL;
	if (!a->head)
	{
		a->head = tmp;
		a->head->next = tmp;
		a->head->prev = tmp;
		return ;
	}
	tmp->next = a->head;
	tmp->prev = a->head->prev;
	(a->head->prev)->next = tmp;
	a->head->prev = tmp;
	a->head = tmp;
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->head;
	if (!a->head)
		return ;
	ft_putstr("pb\n");
	if (a->head != a->head->next)
	{
		a->head = a->head->next;
		a->head->prev = tmp->prev;
		(a->head->prev)->next = a->head;
	}
	else
		a->head = NULL;
	if (!b->head)
	{
		b->head = tmp;
		b->head->next = tmp;
		b->head->prev = tmp;
		return ;
	}
	tmp->next = b->head;
	tmp->prev = b->head->prev;
	(b->head->prev)->next = tmp;
	b->head->prev = tmp;
	b->head = tmp;
	if (!a->head)
		a->head = NULL;
}

void	op_ra(t_stack *a)
{
	ft_putstr("ra\n");
	if (!a->head || !a->head->next)
		return ;
	a->head = a->head->next;
}

void	op_rb(t_stack *b)
{
	if (!b->head || !b->head->next)
		return ;
	b->head = b->head->next;
	ft_putstr("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	ft_putstr("rr\n");
	op_ra(a);
	op_rb(b);
}