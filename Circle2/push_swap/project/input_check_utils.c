/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:23:38 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/12 11:23:44 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_equal_to_other(int num, char **argv, int i)
{
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static char	**argv_to_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	j = 0;
	args = malloc(sizeof(char *) * argc + 1);
	while (i < argc)
		args[j++] = argv[i++];
	args[j] = NULL;
	return (args);
}

char	**get_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv_to_args(argc, argv);
	return (args);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	nb_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
