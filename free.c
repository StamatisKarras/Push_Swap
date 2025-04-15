/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:31:40 by skarras           #+#    #+#             */
/*   Updated: 2025/04/15 08:46:28 by skarras          ###   ########.fr       */
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
	free(stacks->stackb);
	free(stacks->stacka);
	exit(0);
}

void	free_and_exit_stacks_error(t_stacks *stacks)
{
	free(stacks->stacka);
	free(stacks->stackb);
	ft_printf("Error");
	exit(-1);
}
