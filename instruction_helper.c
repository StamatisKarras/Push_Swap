/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:35:05 by skarras           #+#    #+#             */
/*   Updated: 2025/04/21 09:54:27 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*remove_stack(int *stack, int *size)
{
	int	*new_src;
	int	i;
	int	j;

	*size = *size - 1;
	new_src = (int *) ft_calloc(*size, sizeof(int));
	if (!new_src)
		return (NULL);
	i = 0;
	j = 1;
	while (i < *size)
	{
		new_src[i] = stack[j];
		i++;
		j++;
	}
	free(stack);
	return (new_src);
}

int	*add_stack(int *stack, int *size, int n)
{
	int	*new;
	int	i;
	int	j;

	*size = *size + 1;
	new = (int *) ft_calloc(*size, sizeof(int));
	if (!new)
		return (NULL);
	new[0] = n;
	i = 1;
	j = 0;
	while (i < *size)
	{
		new[i] = stack[j];
		i++;
		j++;
	}
	free(stack);
	return (new);
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->sizeb > 1)
	{
		temp = stacks->stackb[1];
		stacks->stackb[1] = stacks->stackb[0];
		stacks->stackb[0] = temp;
		ft_printf("sb\n");
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
