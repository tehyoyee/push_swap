#include "push_swap.h"

void	check_split(int *argc, char **argv)
{
	int		i;
	int		cnt;
	char	**arr;
	int		k;

	i = 1;
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
			argv[k] = NULL;
			while (k > i + cnt)
			{
				argv[k - 1] =  argv[k - cnt];
				k--;
			}
			while (k > i)
			{
				argv[k - 1] = arr[--cnt];
				k--;
			}
		}
		i++;
		free(arr);
	}
}