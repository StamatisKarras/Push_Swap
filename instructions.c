/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:55:29 by skarras           #+#    #+#             */
/*   Updated: 2025/04/09 12:22:19 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stacka[0];
	stacks->stacka = remove_stack(stacks->stacka, &stacks->size);
	stacks->stackb = add_stack(stacks->stackb, &stacks->sizeb, temp);
}

void	push_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stackb[0];
	stacks->stackb = remove_stack(stacks->stackb, &stacks->sizeb);
	stacks->stacka = add_stack(stacks->stacka, &stacks->size, temp);
}

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
	while(i < *size)
	{
		new_src[i] = stack[j];
		i++;
		j++;
	}
	free(stack);
	return(new_src);
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
	while(i < *size)
	{
		new[i] = stack[j];
		i++;
		j++;
	}
	free(stack);
	return(new);
}
