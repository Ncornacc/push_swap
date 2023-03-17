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

void	ft_reverse_rotate(t_stack **stack, char id)
{
	t_stack	*last_to_first;
	t_stack	*last;

	if (id == 'a' || id == 'b')
		ft_printf("rr%c\n", id);
	if (!*stack)
		return ;
	last_to_first = ft_last_to_first(stack);
	last = last_to_first->next;
	last->next = *stack;
	*stack = last;
	last_to_first->next = 0;
	return ;
}

void	ft_rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a, 0);
	ft_reverse_rotate(stack_b, 0);
}

int	ft_stack_sorted(t_stack **stack)
{
	t_stack	*current;
	int		previous;

	if (!*stack)
		return (1);
	current = *stack;
	previous = current->content;
	while (current)
	{
		if (current->content < previous)
			return (0);
		previous = current->content;
		current = current->next;
	}
	return (1);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (ft_stack_sorted(stack_a))
		return ;
	ft_give_index(stack_a, size);
	if (size <= 5)
	{
		if (size == 2)
			ft_swap(stack_a, 'a');
		else if (size == 3)
			ft_sort_three(stack_a);
		else
			ft_choose(stack_a, stack_b, size);
	}
	else
		ft_radix_sort(stack_a, stack_b, size);
}
