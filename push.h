#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Custom_Libft/libft.h"

typedef struct s_stacks
{
	int	*stacka;
	int	**stackb;
	int	size;
} t_stacks;

int		*create_stacka(char **argv, int count);
int		check_ifnum(char *arg);
void	check(char	**argv);
void	free_and_exit_stacka_error(int *stacka);
void	free_and_exit_stacka_sorted(int *stacka);
void	is_sorted(t_stacks *stacks);
int	*copy_stack(t_stacks *stacks);
int	*buble_sort(int	*stack, int size);
int		binary_search(int *stack, int n, int size);

#endif
