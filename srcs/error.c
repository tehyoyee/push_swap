/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:27:52 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:27:53 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_perror(char *msg, int num)
{
	ft_putstr(msg);
	exit(num);
}

void	check_reduplicate(int argc, t_node *node1)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 1;
	while (i < argc - 1)
	{
		temp = node1->next;
		j = i + 1;
		while (j < argc)
		{
			if (node1->value - temp->value == 0)
			{
				exit_perror("Error\n", 1);
			}
			temp = temp->next;
			j++;
		}
		node1 = node1->next;
		i++;
	}
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check_decimal(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			exit_perror("Error\n", 1);
		i++;
	}
}

void	check_sorted(t_node *node, size_t node_size)
{
	size_t	i;

	i = 0;
	while (i < node_size - 1)
	{
		if (node->order + 1 != (node->next)->order)
		{
			return ;
		}
		i++;
		node = node->next;
	}
	exit(0);
}
