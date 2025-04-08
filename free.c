/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:31:40 by skarras           #+#    #+#             */
/*   Updated: 2025/04/08 10:29:11 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	free_and_exit_stacka_error(int *stacka)
{
	free(stacka);
	ft_printf("Error\n");
	exit(-1);
}

void	free_and_exit_stacka_sorted(int *stacka)
{
	free(stacka);
	ft_printf("Stack is sorted\n");
	exit(0);
}
