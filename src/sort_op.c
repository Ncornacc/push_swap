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

void	ft_swap(t_stack **stack, char id)
{
	t_stack	*first;
	t_stack	*second;

	if (id == 'a' || id == 'b')
		ft_printf("s%c\n", id);
	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
		return ;
	}
}

void	ft_swapswap(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 0);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, char id)
{
	t_stack	*first_b;
	t_stack	*first_a;

	if (id == 'b')
	{
		ft_printf("pb\n");
		if (*stack_a)
		{
			first_a = *stack_a;
			*stack_a = first_a->next;
			first_a->next = *stack_b;
			*stack_b = first_a;
		}
	}
	else if (id == 'a')
	{
		ft_printf("pa\n");
		if (*stack_b)
		{
			first_b = *stack_b;
			*stack_b = first_b->next;
			first_b->next = *stack_a;
			*stack_a = first_b;
		}
	}
}

void	ft_rotate(t_stack **stack, char id)
{
	t_stack	*last;

	if (id == 'a' || id == 'b')
		ft_printf("r%c\n", id);
	if (!*stack)
		return ;
	last = ft_get_last(stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}

void	ft_rotaterotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
}
