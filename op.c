#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	op_sa(t_stack a)
{
	if (a.head != NULL)
		swap_value(&(a.head)->value, &((a.head)->next)->value);
	printf("sa\n");

}

void	op_sb(t_stack b)
{
	if (b.head != NULL)
		swap_value(&(b.head)->value, &((b.head)->next)->value);
	printf("sb\n");
}

void	op_ss(t_stack a, t_stack b)
{
	if (a.head != NULL)
		swap_value(&(a.head)->value, &((a.head)->next)->value);
	if (b.head != NULL)
		swap_value(&(b.head)->value, &((b.head)->next)->value);
	printf("ss\n");
}