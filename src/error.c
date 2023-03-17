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

int	arg_nbr(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (!((s[i] >= 48 && s[i] <= 57) || s[i] == 45))
			return (1);
		i++;
	}
	return (0);
}

static	int	check_dup_n(t_stack **stack, t_stack *n)
{
	t_stack	*current;

	if (!*stack)
		return (0);
	current = *stack;
	while (current && current != n)
	{
		if (current->content == n->content)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_dup_s(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
		return (0);
	current = *stack;
	while (current)
	{
		if (check_dup_n(stack, current))
			return (1);
		current = current->next;
	}
	return (0);
}

static int	size_n(int n)
{
	int	size;

	size = 0;
	while (n < 0)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

int	max_int(char *s)
{
	int	len;
	int	size;
	int	n;

	len = ft_strlen(s);
	n = ft_atoi(s);
	size = 0;
	if (n <= 0)
		size = size_n(n);
	else
	{
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	if (size != len)
		return (1);
	return (0);
}
