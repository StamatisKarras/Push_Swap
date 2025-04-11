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

void	push_swap(t_stacks	*stacks)
{
	int mask;
	int	i;
	int	sizea;
	int sizeb;

	mask = 1;
	while(is_sorted(stacks) == -1)
	{
		sizea = stacks->size;
		i = 0;
		while (i < sizea)
		{
			if (stacks->stacka[0] & mask)
				ra(stacks);
			else
				pb(stacks);
			i++;
		}
		sizeb = stacks->sizeb;
		i = 0;
		while (i < sizeb)
		{
			pa(stacks);
			i++;
		}
		mask = mask << 1;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			*copy;

	stacks.size = argc - 1;
	stacks.sizeb = 0;
	if(argc < 2)
	{
		ft_printf("Not enough arguments\n");
		exit(-1);
	}
	check(argv + 1);
	stacks.stacka = create_stacka(argv + 1, stacks.size);
	if (is_sorted(&stacks) == 1)
		free_and_exit_sorted(&stacks);
	copy = buble_sort(copy_stack(&stacks), stacks.size);
	convert_to_order(&stacks, copy);
	stacks.stackb = (int *) ft_calloc(0, sizeof(int));
	push_swap(&stacks);
	free_and_exit_sorted(&stacks);
	return (0);
}
