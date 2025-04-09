/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:22:23 by skarras           #+#    #+#             */
/*   Updated: 2025/04/09 10:29:49 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_ifnum(char *arg)
{
	int		i;
	int		res;
	char	*c_res;

	res = ft_atoi(arg);
	c_res = ft_itoa(res);
	i = 0;
	while(arg[i])
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
	int 		res;

	i = 0;
	while (argv[i])
	{
		res = check_ifnum(argv[i]);
		if (res == -1)
		{
			ft_printf("error\n");
			exit(-1);
		}
		i++;
	}
}

void	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size - 1)
	{
		if (stacks->stacka[i] > stacks->stacka[i + 1])
			return ;
		i++;
	}
	free_and_exit_sorted(stacks);
}
