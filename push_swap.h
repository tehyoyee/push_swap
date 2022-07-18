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
t_node	*ft_nodelast(t_node *node);
t_node	*ft_nodenew(int value);
void	ft_nodeprint(t_node *node);
int		ft_atoi(const char *str);
void	ft_nodeprint_r(t_node *node);



#endif
