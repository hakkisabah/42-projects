/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:01:22 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:20:37 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void	fill_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack		*tmp;
	long int	nb;
	int			i;
	char		**args;

	args = get_args(argc, argv);
	argc = ft_strslen(args);
	i = 0;
	while (i < argc)
	{
		nb = ft_atoi(args[i]);
		tmp = ft_lstnew((int)nb);
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	free_arr(args, ft_strslen(argv));
}
