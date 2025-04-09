/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:31:40 by skarras           #+#    #+#             */
/*   Updated: 2025/04/09 10:31:38 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	free_and_exit_stacka_error(int *stacka)
{
	free(stacka);
	ft_printf("Error\n");
	exit(-1);
}

void	free_and_exit_sorted(t_stacks *stacks)
{
	if (stacks->stackb)
		free(stacks->stackb);
	free(stacks->stacka);
	ft_printf("Stack is sorted\n");
	exit(0);
}

void	free_and_exit_stacks_error(t_stacks *stacks)
{
	free(stacks->stacka);
	free(stacks->stackb);
	ft_printf("Error");
	exit(-1);
}
