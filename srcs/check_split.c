/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:27:28 by taehykim          #+#    #+#             */
/*   Updated: 2022/07/29 14:27:29 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	check_split(int *argc, char **argv, int i, int k)
{
	int		cnt;
	char	**arr;

	while (argv[i])
	{
		k = *argc;
		arr = ft_split(argv[i], ' ');
		cnt = 1;
		if (arr[cnt])
		{
			while (arr[cnt])
				cnt++;
			*argc += (cnt - 1);
			k = *argc;
			argv[k++] = NULL;
			while (k-- > i + cnt + 1)
				argv[k - 1] = argv[k - cnt];
			while (k > i)
				argv[k-- - 1] = arr[--cnt];
		}
		ft_free(arr);
		i++;
	}
}
