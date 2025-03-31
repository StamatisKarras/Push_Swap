#include "push.h"

/*int	*push_swap(int **stackb, int *stacka)
{

}

int	**create_stackb()
{

}*/

int *create_stacka(char **argv, int count)
{
	int	*array;
	int	i;

	array = (int *) malloc(count * sizeof(int));
	if (!array)
		exit(-1);
	i = 0;
	while(argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	return(array);
}

int	check(char *arg)
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

int	main(int argc, char *argv[])
{
	int	i;
	int res;
	(void) argc;

	i = 1;
	while (argv[i])
	{
		res = check(argv[i]);
		if (res == -1)
		{
			ft_printf("error\n");
			exit(-1);
		}
		i++;
	}
	return (0);
}
