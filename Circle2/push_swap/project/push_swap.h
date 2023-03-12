/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:53:35 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:29:31 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		is_equal_to_other(int num, char **argv, int i);
char	**get_args(int argc, char **argv);
int		is_sign(char c);
int		nb_str_cmp(const char *s1, const char *s2);

int		is_input_correct(int argc, char **argv);

t_stack	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);

void	index_stack(t_stack **stack);
void	fill_stack(t_stack **stack_a, int argc, char **argv);

void	ft_putstr(char *str);
void	exit_to_error(void);

int		ft_strslen(char **str);
int		get_distance(t_stack *stack, int index);
int		is_sorted(t_stack **stack);
void	free_arr(char **str, int argvlen);
void	free_stack(t_stack **stack);

void	sort_3_op(t_stack *head, t_stack **stack_a, int min, int next_min);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif