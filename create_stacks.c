/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:24:25 by skarras           #+#    #+#             */
/*   Updated: 2025/04/04 11:45:55 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"


/*int	**create_stackb(void)
{

}*/

int *create_stacka(char **argv, int count)
{
	int	*array;
	int	i;
	int	j;

	array = (int *) malloc(count * sizeof(int));
	if (!array)
		exit(-1);
	i = 0;
	while(argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		j = 1;
		while (i - j >= 0)
		{
			if (array[i] == array[i - j])
				free_and_exit_stacka_error(array);
			j++;
		}
		i++;
	}
	return(array);
}

//int	*convert_to_order(t_stacks *stacks, int *buble)
//{

//}

int		binary_search(int *stack, int n, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (n > stack[(size + i) / 2])
			i = (size + i) / 2;
		else
		{
			while(i < size)
			{
				if (stack[i] == n)
					return (i);
				i++;
			}
			return (0);
		}
	}
	return (0);
}
