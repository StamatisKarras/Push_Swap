/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:22:40 by skarras           #+#    #+#             */
/*   Updated: 2025/04/04 09:22:40 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*push_swap(t_stacks	*stacks)
{

}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			*copy;

	stacks.size = argc - 1;
	if(argc < 2)
	{
		ft_printf("Not enough arguments\n");
		exit(-1);
	}
	check(argv + 1);
	stacks.stacka = create_stacka(argv + 1, stacks.size);
	is_sorted(&stacks);
	copy = buble_sort(copy_stack(&stacks), stacks.size);
	convert_to_order(&stacks, copy);
	stacks.stackb = create_stackb(&stacks);
	push_swap(&stacks);
	return (0);
}
