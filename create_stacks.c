/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:24:25 by skarras           #+#    #+#             */
/*   Updated: 2025/04/16 10:18:15 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*create_stacka(char **argv, int count)
{
	int	*array;
	int	i;
	int	j;

	array = (int *) malloc(count * sizeof(int));
	if (!array)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	i = 0;
	while (argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		j = 1;
		while (i - j >= 0)
		{
			if (array[i] == array[i - j])
				free_and_exit_stacka_error(array);
			j++;
		}
		i++;
	}
	return (array);
}
