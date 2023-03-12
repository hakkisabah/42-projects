/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:29:24 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:29:47 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* Get the biggest element in the stack for radix sort
* and return the number logaritmic size of the biggest element
* its mean how many bits we need to represent the biggest element
**/
static int	get_log2_element_size(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
* Radix sort algorithm with binary representation :
* Radix sort actually use logaritmic time complexity
* for example if we have 81 elements in the stack
* we will need 7 bits to represent the biggest number for log2 81
* Logarithm, getting for the total number of elements given,
* how many times which number will be multiplied by itself.
* So we have divide of parts automatically for sort them.
* if ((head_a->index >> i) & 1) == 1 means we are checking
* the bit in the index of the element in the stack
**/
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		stack_log2_size;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	stack_log2_size = get_log2_element_size(stack_a);
	while (i < stack_log2_size)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
