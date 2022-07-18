#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
}				t_stack;

void	ft_nodeadd_back(t_node **node, t_node *new);
void	ft_nodeadd_front(t_node **node, t_node *new);
t_node	*ft_nodelast(t_node *node);
t_node	*ft_nodenew(int value);
void	ft_nodeprint(t_node *node1, t_node *node2);
int		ft_atoi(const char *str);
void	ft_nodeprint_r(t_node *node1, t_node *node2);
void	op_sa(t_stack a);
void	op_sb(t_stack b);
void	op_ss(t_stack a, t_stack b);
void	op_pa(t_stack *a, t_stack *b);
void	swap_value(int *a, int *b);
void	op_pb(t_stack *a, t_stack *b);
void	ft_nodedel(t_node **node);
void	ft_nodedel_bottom(t_node **node);
void	op_ra(t_stack *a);
void	op_rb(t_stack *a);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

#endif
