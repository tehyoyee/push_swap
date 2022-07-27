/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:52:57 by taehykim          #+#    #+#             */
/*   Updated: 2022/01/31 11:59:53 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_len(unsigned long long result)
{
	int	num_len;

	num_len = 0;
	while (result > 0)
	{
		num_len++;
		result /= 10;
	}
	return (num_len);
}

int	get_answer(const char *str, int sign)
{
	unsigned long long	result;
	int					arr_len;

	result = 0;
	arr_len = 0;
	while ('0' <= *str && *str <= '9')
	{
		arr_len++;
		result = result * 10 + *str - 48;
		if ((result > 2147483647) && sign == 1)
			exit_perror("argument number is more than int_max", 1);
		if ((result > 2147483648) && sign == -1)
			exit_perror("argument number is less than int_min", 1);
		str++;
	}
	return (sign * (int)result);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	if ('0' > *str || *str > '9')
		return (0);
	return (get_answer(str, sign));
}
