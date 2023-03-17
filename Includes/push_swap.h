/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 14:06:31 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/02/03 14:06:32 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				content;
	unsigned int	pos;
	struct s_stack	*next;
}	t_stack;

/* Errors */
int		check_dup_s(t_stack **stack);
int		max_int(char *s);
int		arg_nbr(char *s);

/* Stack Operations */
t_stack	*ft_get_max(t_stack **stack);
t_stack	*ft_last_to_first(t_stack **stack);
t_stack	*ft_create_nbr(int nb);
t_stack	*ft_get_last(t_stack **stack);
t_stack	*ft_get_min(t_stack **stack, long limit);
t_stack	**ft_create(int argc, char **argv, int ordered);
void	ft_give_index(t_stack **stack, int size);
void	ft_stack_push(t_stack **stack, t_stack *new);
void	ft_free(t_stack ***stack, char ***argv, int argc, int ordered);

/* Sorting Functions*/
int		ft_stack_sorted(t_stack **stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_choose(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_sort_three(t_stack **stack);

/* Sorting Operation*/
void	ft_swap(t_stack **stack, char id);
void	ft_swapswap(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotaterotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_rr_rotate(t_stack **stack_a, t_stack **stack_b);

/* Main */
char	**ft_normalize(char **argv);
int		ft_get_len(char **argv);
void	ft_single_arg(int *argc, char ***argv, int *ordered);

#endif
