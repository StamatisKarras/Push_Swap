/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:11:59 by skarras           #+#    #+#             */
/*   Updated: 2025/04/14 11:11:59 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./Custom_Libft/libft.h"

typedef struct s_stacks
{
	int	*stacka;
	int	*stackb;
	int	size;
	int	sizeb;
}	t_stacks;

int		*create_stacka(char **argv, int count);
int		check_ifnum(char *arg);
void	check(char	**argv);
void	free_and_exit_stacka_error(int *stacka);
void	free_and_exit_sorted(t_stacks *stacks);
int		*copy_stack(t_stacks *stacks);
int		*buble_sort(int	*stack, int size);
int		binary_search(int *stack, int n, int size);
void	convert_to_order(t_stacks *stacks, int *buble);
void	free_and_exit_stacks_error(t_stacks *stacks);
int		*remove_stack(int *stack, int *size);
int		*add_stack(int *stack, int *size, int n);
void	pb(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);

#endif
