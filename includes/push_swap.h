/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:29:36 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:29:38 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	size_t			order;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
}				t_stack;

typedef struct s_range
{
	size_t	small;
	size_t	big;
}				t_range;

t_node	*ft_nodelast(t_node *node);
t_node	*ft_nodenew(int value);
void	ft_nodeadd_back(t_node **node, t_node *new);

//		checker

void	check_decimal(int argc, char **argv);
void	check_reduplicate(int argc, t_node *node1);
void	exit_perror(char *msg, int num);
char	**ft_split(char const *s, char c);
void	check_split(int *argc, char **argv, int i);
void	check_sorted(t_node *node, size_t node_size);
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

//		rotation

void	swap_value(int *a, int *b);
void	op_sa(t_stack a);
void	op_sb(t_stack b);
void	op_ss(t_stack a, t_stack b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *a);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

//		sort

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv);
void	init_node_order(t_stack *a, int argc);
void	sort_under_5(t_stack *a, t_stack *b, size_t node_size);
size_t	get_order_pos(t_node *a, size_t node_size, size_t order);
size_t	node_count(t_node *node);
void	push_a_to_b(t_stack *a, t_stack *b);
void	push_b_to_a(t_stack *a, t_stack *b);
size_t	get_order_pos(t_node *a, size_t node_size, size_t order);
size_t	get_order_max(t_node *a, size_t node_size);

#endif
