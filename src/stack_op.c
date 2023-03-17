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

t_stack	*ft_get_last(t_stack **stack)
{
	t_stack	*current;

	if (stack == 0)
		return (0);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

t_stack	*ft_create_nbr(int nb)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (0);
	res->content = nb;
	res->pos = 0;
	res->next = 0;
	return (res);
}

t_stack	*ft_last_to_first(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	current = *stack;
	if (stack == 0)
		return (0);
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}

t_stack	*ft_get_min(t_stack **stack, long limit)
{
	t_stack	*current;
	t_stack	*min;
	int		min_found;

	if (!*stack)
		return (0);
	current = *stack;
	min_found = 2147483647;
	min = *stack;
	while (current)
	{
		if (current->content > limit && current->content <= min_found)
		{
			min_found = current->content;
			min = current;
		}
		current = current->next;
	}
	return (min);
}

t_stack	*ft_get_max(t_stack **stack)
{
	t_stack	*current;
	t_stack	*max_elmt;

	if (!*stack)
		return (0);
	current = *stack;
	max_elmt = *stack;
	while (current)
	{
		if (current->pos > max_elmt->pos)
			max_elmt = current;
		current = current->next;
	}
	return (max_elmt);
}
