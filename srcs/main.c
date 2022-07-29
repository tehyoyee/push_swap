/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:27:35 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:27:37 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	check_split(&argc, argv, 1);
	check_decimal(argc, argv);
	init_stack(&a, &b, argc, argv);
	init_node_order(&a, argc);
	check_reduplicate(argc, a.head);
	check_sorted(a.head, node_count(a.head));
	if (argc <= 6)
		sort_under_5(&a, &b, node_count(a.head));
	else
	{
		push_a_to_b(&a, &b);
		push_b_to_a(&a, &b);
	}
}
