/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:42:35 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:28:57 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

static void	is_require_to_sort(t_stack **stack_a, int stack_size)
{
	if (is_sorted(stack_a) || stack_size == 1 || stack_size == 0)
	{
		free_stack(stack_a);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		stack_size;

	if (argc < 2 || !argv[1][0])
		return (0);
	if (!is_input_correct(argc, argv))
		exit_to_error();
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	fill_stack(stack_a, argc, argv);
	index_stack(stack_a);
	stack_size = ft_lstsize(*stack_a);
	*stack_b = NULL;
	is_require_to_sort(stack_a, stack_size);
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
