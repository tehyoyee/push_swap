#include "push_swap.h"

void	exit_perror(char *msg, int num)
{
	ft_putstr(msg);
	exit(num);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (*s1 == '+' || *s1 == '-')
		s1++;
	if (*s2 == '+' || *s2 == '-')
		s2++;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_reduplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				exit_perror("reduplicated arguments", 1);
			j++;
		}
		i++;
	}
	return (1);
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
			exit_perror("incorrect argument format", 1);
		i++;
	}
}
