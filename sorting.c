/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:34:09 by skarras           #+#    #+#             */
/*   Updated: 2025/04/21 09:41:38 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*buble_sort(int	*stack, int size)
{
	int	ordered;
	int	temp;
	int	i;

	ordered = -1;
	while (ordered != 0)
	{
		i = 1;
		ordered = 0;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
			{
				temp = stack[i - 1];
				stack[i - 1] = stack[i];
				stack[i] = temp;
				ordered = -1;
			}
			i++;
		}
	}
	return (stack);
}

int	*copy_stack(t_stacks *stacks)
{
	int	*copy;
	int	i;

	copy = (int *) ft_calloc(stacks->size, sizeof(int));
	if (!copy)
		free_and_exit_stacks_error(stacks);
	i = 0;
	while (i < stacks->size)
	{
		copy[i] = stacks->stacka[i];
		i++;
	}
	return (copy);
}
