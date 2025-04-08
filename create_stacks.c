/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:24:25 by skarras           #+#    #+#             */
/*   Updated: 2025/04/08 11:09:25 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"


int	*create_stackb(t_stacks *stacks)
{
	int	*stackb;

	stackb = (int *) ft_calloc(stacks->size, sizeof(int));
	if (!stackb)
		free_and_exit_stacka_error(stacks->stacka);
	return (stackb);
}

int *create_stacka(char **argv, int count)
{
	int	*array;
	int	i;
	int	j;

	array = (int *) malloc(count * sizeof(int));
	if (!array)
		exit(-1);
	i = 0;
	while(argv[i])
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
	return(array);
}
