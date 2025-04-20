/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:22:23 by skarras           #+#    #+#             */
/*   Updated: 2025/04/20 17:00:22 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_ifnum(char *arg)
{
	int		i;
	int		res;
	char	*c_res;

	if (ft_strncmp(arg, "", 1) == 0)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	res = ft_atoi(arg);
	c_res = ft_itoa(res);
	if (c_res == NULL)
		return (-1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] != c_res[i])
		{
			free(c_res);
			return (-1);
		}
		i++;
	}
	free(c_res);
	return (0);
}

void	check(char	**argv)
{
	int			i;
	int			res;

	i = 0;
	while (argv[i])
	{
		res = check_ifnum(argv[i]);
		if (res == -1)
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		i++;
	}
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size - 1)
	{
		if (stacks->stacka[i] > stacks->stacka[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
