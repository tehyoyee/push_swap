#include "push_swap.h"

void	sort_case2(int a, int b)
{
	if (a > b)
		ft_putstr("sa\n");
	exit(0);
}

void	sort_case3(int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exit(0);
	if (a < b && a < c && b > c)
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
		exit(0);
	}
	if (a > b && a < c && b < c)
	{
		ft_putstr("sa\n");
		exit(0);
	}
	if (a < b && a > c && b > c)
	{
		ft_putstr("rra\n");
		exit(0);
	}
	if (a > b && a > c && b < c)
	{
		ft_putstr("ra\n");
		exit(0);
	}
	if (a > b && a > c && b > c)
	{
		ft_putstr("sa\n");
		ft_putstr("rra\n");
		exit(0);
	}
}