/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:34:22 by skarras           #+#    #+#             */
/*   Updated: 2025/04/21 09:47:41 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	convert_to_order(t_stacks *stacks, int *buble)
{
	int		i;
	int		temp;

	i = 0;
	while (i < stacks->size)
	{
		temp = binary_search(buble, stacks->stacka[i], stacks->size);
		if (temp == -1)
		{
			free(buble);
			free_and_exit_stacks_error(stacks);
		}
		stacks->stacka[i] = temp;
		i++;
	}
	free(buble);
}

int	binary_search(int *stack, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n > stack[(size + i) / 2])
			i = (size + i) / 2;
		else
		{
			while (i < size)
			{
				if (stack[i] == n)
					return (i);
				i++;
			}
			return (-1);
		}
	}
	return (-1);
}
