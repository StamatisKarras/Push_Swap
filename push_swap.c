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
	int	mask;
	int	i;
	int	sizea;
	int	sizeb;

	mask = 1;
	while (is_sorted(stacks) == -1)
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
		while (i++ < sizeb)
			pa(stacks);
		mask = mask << 1;
	}
}

void	big_num(t_stacks *stacks)
{
	int			*copy;
	int			*buble;

	copy = copy_stack(stacks);
	buble = buble_sort(copy, stacks->size);
	if (!buble)
	{
		free(copy);
		free_and_exit_stacks_error(stacks);
	}
	convert_to_order(stacks, buble);
	push_swap(stacks);
}

void	small_num(t_stacks *stacks)
{
	if (stacks->size == 2)
		sort_2(stacks);
	else if (stacks->size == 3)
		sort_3(stacks);
	else if (stacks->size == 4)
		sort_4(stacks);
	else if (stacks->size == 5)
		sort_5(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks.size = argc - 1;
	stacks.sizeb = 0;
	if (argc < 2)
		exit(-1);
	check(argv + 1);
	stacks.stacka = create_stacka(argv + 1, stacks.size);
	stacks.stackb = (int *) ft_calloc(0, sizeof(int));
	if (!stacks.stackb)
		free_and_exit_stacks_error(&stacks);
	if (is_sorted(&stacks) == 1)
		free_and_exit_sorted(&stacks);
	if (stacks.size <= 5)
		small_num(&stacks);
	else
		big_num(&stacks);
	free_and_exit_sorted(&stacks);
	return (0);
}
