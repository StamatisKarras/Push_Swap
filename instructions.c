/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:55:29 by skarras           #+#    #+#             */
/*   Updated: 2025/04/20 17:08:02 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pb(t_stacks *stacks)
{
	int	temp;
	int	*check;

	temp = stacks->stacka[0];
	check = remove_stack(stacks->stacka, &stacks->size);
	if (!check)
		free_and_exit_stacks_error(stacks);
	stacks->stacka = check;
	check = add_stack(stacks->stackb, &stacks->sizeb, temp);
	if (!check)
		free_and_exit_stacks_error(stacks);
	stacks->stackb = check;
	ft_printf("pb\n");
}

void	pa(t_stacks *stacks)
{
	int	temp;
	int	*check;

	temp = stacks->stackb[0];
	check = remove_stack(stacks->stackb, &stacks->sizeb);
	if (!check)
		free_and_exit_stacks_error(stacks);
	stacks->stackb = check;
	check = add_stack(stacks->stacka, &stacks->size, temp);
	if (!check)
		free_and_exit_stacks_error(stacks);
	stacks->stacka = check;
	ft_printf("pa\n");
}

void	ra(t_stacks *stacks)
{
	int	*new_stack;
	int	i;
	int	j;

	new_stack = (int *) ft_calloc(stacks->size, sizeof(int));
	if (!new_stack)
		free_and_exit_stacks_error(stacks);
	i = 1;
	j = 0;
	while (i < stacks->size)
	{
		new_stack[j] = stacks->stacka[i];
		i++;
		j++;
	}
	new_stack[j] = stacks->stacka[0];
	free(stacks->stacka);
	stacks->stacka = new_stack;
	ft_printf("ra\n");
}

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->size > 1)
	{
		temp = stacks->stacka[1];
		stacks->stacka[1] = stacks->stacka[0];
		stacks->stacka[0] = temp;
		ft_printf("sa\n");
	}
}

void	rra(t_stacks *stacks)
{
	int	i;
	int	j;
	int	*new_arr;

	i = 1;
	j = 0;
	new_arr = (int *) ft_calloc(stacks->size, sizeof(int));
	if (!new_arr)
		free_and_exit_stacks_error(stacks);
	new_arr[0] = stacks->stacka[stacks->size - 1];
	while (i < stacks->size)
	{
		new_arr[i] = stacks->stacka[j];
		i++;
		j++;
	}
	free(stacks->stacka);
	stacks->stacka = new_arr;
	ft_printf("rra\n");
}
