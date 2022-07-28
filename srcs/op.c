#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_value_size_t(size_t *a, size_t *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	op_sa(t_stack a)
{
	if (a.head != NULL)
	{
		swap_value(&(a.head)->value, &((a.head)->next)->value);
		swap_value_size_t(&(a.head)->order, &((a.head)->next)->order);
	}
	ft_putstr("sa\n");
}

void	op_sb(t_stack b)
{
	if (b.head != NULL)
	{
		swap_value(&(b.head)->value, &((b.head)->next)->value);
		swap_value_size_t(&(b.head)->order, &((b.head)->next)->order);
	}
	ft_putstr("sb\n");
}

void	op_ss(t_stack a, t_stack b)
{
	if (a.head != NULL)
		swap_value(&(a.head)->value, &((a.head)->next)->value);
	if (b.head != NULL)
		swap_value(&(b.head)->value, &((b.head)->next)->value);
	ft_putstr("ss\n");
}
