/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:57:57 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:24:37 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

static int	check_number_and_max(char *nbs)
{
	int			i;
	long int	nb;

	nb = ft_atol(nbs);
	if (nb > MAX_INT || nb < MIN_INT)
		return (0);
	i = 0;
	if (is_sign(nbs[i]) && nbs[i + 1] != '\0')
		i++;
	while (nbs[i] && ft_isdigit(nbs[i]))
		i++;
	if (nbs[i] != '\0' && !ft_isdigit(nbs[i]))
		return (0);
	return (1);
}

static int	is_zero(char *nbs)
{
	int	i;

	i = 0;
	if (is_sign(nbs[i]))
		i++;
	while (nbs[i] && nbs[i] == '0')
		i++;
	if (nbs[i] != '\0')
		return (0);
	return (1);
}

static int	is_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[j])
		{
			if (j != i && nb_str_cmp(args[i], args[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_input_correct(int argc, char **argv)
{
	int		i;
	int		zero_duplicate;
	char	**args;

	args = get_args(argc, argv);
	i = 0;
	zero_duplicate = 0;
	while (args[i])
	{
		if (!check_number_and_max(args[i])
			|| is_equal_to_other(ft_atoi(args[i]), args, (i + 1)))
		{
			free_arr(args, ft_strslen(argv));
			return (0);
		}
		zero_duplicate += is_zero(args[i++]);
	}
	if (zero_duplicate > 1 || is_duplicate(args))
	{
		free_arr(args, ft_strslen(argv));
		return (0);
	}
	free_arr(args, ft_strslen(argv));
	return (1);
}
