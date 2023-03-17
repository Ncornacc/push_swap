/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/18 14:50:34 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/02/18 14:50:35 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_give_index(t_stack **stack, int size)
{
	int		i;
	long	min_found;
	t_stack	*min;

	min_found = -2147483649;
	i = 0;
	while (i < size)
	{
		min = ft_get_min(stack, min_found);
		min->pos = i;
		min_found = min->content;
		i++;
	}
}

void	ft_stack_push(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_get_last(stack);
	last->next = new;
	return ;
}

void	ft_free(t_stack ***stack, char ***argv, int argc, int ordered)
{
	t_stack	*current;
	t_stack	*next;
	int		i;

	if (*stack)
	{
		current = *(*stack);
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(*stack);
	}
	i = 0;
	if (ordered && argv)
	{
		while (i < argc)
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}

t_stack	**ft_create(int argc, char **argv, int ordered)
{
	int		i;
	t_stack	**result;

	i = 0;
	result = ft_calloc(1, sizeof(t_stack *));
	if (!result)
		return (0);
	while (++i < argc)
	{
		if (arg_nbr(argv[i]) || max_int(argv[i]))
		{
			ft_printf("Error\n");
			ft_free(&result, &argv, argc, ordered);
			exit(1);
		}
		ft_stack_push(result, ft_create_nbr(ft_atoi(argv[i])));
	}
	if (check_dup_s(result))
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (result);
}
