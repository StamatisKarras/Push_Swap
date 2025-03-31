#include "push.h"

static void	free_and_exit_stacka(int *stacka)
{
	free(stacka);
	ft_printf("Error Duplicate Detected\n");
	exit(-1);
}

/*int	*push_swap(t_stacks	*stacks)
{

}*/

int	**create_stackb(void)
{
	int	**stackb;

	stackb = (int **) ft_calloc(18, sizeof(int *));
	if (stackb)
}

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
				free_and_exit_stacka(array);
			j++;
		}
		i++;
	}
	return(array);
}

int	check_ifnum(char *arg)
{
	int		i;
	int		res;
	char	*c_res;

	res = ft_atoi(arg);
	c_res = ft_itoa(res);
	i = 0;
	while(arg[i])
	{
		if (arg[i] != c_res[i])
		{
			free(c_res);
			return (-1);
		}
		i++;
	}
	free(c_res);
	return (0);
}

void	check(char	**argv)
{
	int			i;
	int 		res;

	i = 0;
	while (argv[i])
	{
		res = check_ifnum(argv[i]);
		if (res == -1)
		{
			ft_printf("error\n");
			exit(-1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int	i;

	stacks.size = argc - 1;
	if(argc < 2)
	{
		ft_printf("Not enough arguments\n");
		exit(-1);
	}
	check(argv + 1);
	stacks.stacka = create_stacka(argv + 1, stacks.size);
	i = 0;
	while(i < stacks.size)
	{
		ft_printf("%d\n", stacks.stacka[i]);
		i++;
	}
	return (0);
}
