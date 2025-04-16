/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:33:16 by skarras           #+#    #+#             */
/*   Updated: 2025/04/16 10:00:52 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_2(t_stacks *stacks)
{
	sa(stacks);
}

void	sort_3(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stacka[0];
	b = stacks->stacka[1];
	c = stacks->stacka[2];
	if (a > b && a < c)
		sa(stacks);
	else if (a < b && a > c)
		rra(stacks);
	else if (a > b && a > c && b < c)
		ra(stacks);
	else if (a > b && a > c && b > c)
	{
		ra(stacks);
		sa(stacks);
	}
	else if (a < b && a < c && b > c)
	{
		rra(stacks);
		sa(stacks);
	}
}

void	sort_4(t_stacks	*stacks)
{
	int	*buble;
	int	*copy;

	copy = copy_stack(stacks);
	buble = buble_sort(copy, stacks->size);
	if (!buble)
		free_and_exit_stacka_error(stacks->stacka);
	convert_to_order(stacks, buble);
	if (!stacks->stacka)
		free_and_exit_stacks_error(stacks);
	if (stacks->stacka[0] == 2)
		ra(stacks);
	pb(stacks);
	sort_3(stacks);
	pa(stacks);
	if (stacks->stacka[0] != 0)
	{
		if (stacks->stacka[0] == 1)
			sa(stacks);
		else
			ra(stacks);
	}
}

void	sort_5(t_stacks	*stacks)
{
	int	*buble;
	int	*copy;

	copy = copy_stack(stacks);
	buble = buble_sort(copy, stacks->size);
	if (!buble)
		free_and_exit_stacka_error(stacks->stacka);
	convert_to_order(stacks, buble);
	if (!stacks->stacka)
		free_and_exit_stacks_error(stacks);
	while (stacks->stacka[0] == 2 || stacks->stacka[0] == 3)
		ra(stacks);
	pb(stacks);
	sort_4(stacks);
	pa(stacks);
	if (stacks->stacka[0] != 0)
	{
		if (stacks->stacka[0] == 1)
			sa(stacks);
		else
			ra(stacks);
	}
}
