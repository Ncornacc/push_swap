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

void	ft_sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
		ft_swap(stack, 'a');
	else if (first > second && second > third && first > third)
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate(stack, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate(stack, 'a');
}

static void	ft_sort_greatest(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
	{
		while ((*stack_a)->pos < ft_get_max(stack_a)->pos)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
		size--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_push(stack_a, stack_b, 'a');
		ft_rotate(stack_a, 'a');
	}
}

static void	ft_sort_smallest(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
	{
		while ((*stack_a)->pos > ft_get_min(stack_a, -2147483649)->pos)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
		size--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_push(stack_a, stack_b, 'a');
}

void	ft_choose(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		index;
	t_stack	*current;

	current = *stack_a;
	index = 0;
	while (current->pos < ft_get_max(stack_a)->pos)
	{
		index++;
		current = current->next;
	}
	if (index < size / 2)
		ft_sort_greatest(stack_a, stack_b, size);
	else
		ft_sort_smallest(stack_a, stack_b, size);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int				i;
	unsigned int	bit;
	t_stack			*current;

	bit = 0;
	while (bit < 32)
	{
		i = 0;
		current = *stack_a;
		while (i < size)
		{
			if ((1 & (current->pos >> bit)) == 0)
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			current = *stack_a;
			i++;
		}
		current = *stack_b;
		while (*stack_b)
			ft_push(stack_a, stack_b, 'a');
		bit++;
		if (ft_stack_sorted(stack_a))
			return ;
	}
}
