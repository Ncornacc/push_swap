/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/18 14:15:37 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/02/18 14:15:38 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_normalize(char **argv)
{
	char	**result;
	char	*str;

	str = ft_strjoin("lol ", argv[1]);
	if (!str)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	result = ft_split(str, ' ');
	free(str);
	if (!result)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (result);
}

int	ft_get_len(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	ft_single_arg(int *argc, char ***argv, int *ordered)
{
	*argv = ft_normalize(*argv);
	*argc = ft_get_len(*argv);
	*ordered = 1;
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		ordered;

	ordered = 0;
	if (argc == 2)
	{
		ft_single_arg(&argc, &argv, &ordered);
		if (!argv)
			return (0);
	}
	stack_a = ft_create(argc, argv, ordered);
	stack_b = ft_create(0, argv, ordered);
	if (!stack_a || !stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free(&stack_a, &argv, argc, ordered);
		ft_free(&stack_b, &argv, argc, ordered);
		return (0);
	}
	ft_sort(stack_a, stack_b, argc - 1);
	ft_free(&stack_a, &argv, argc, ordered);
	ft_free(&stack_b, 0, 0, ordered);
	return (0);
}
