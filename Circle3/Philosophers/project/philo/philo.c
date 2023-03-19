/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:34:27 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/20 00:47:36 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		r;

	if (argc != 5 && argc != 6)
		return (throw_error("Invalid amount of arguments"));
	r = init_philos(&rules, argv);
	if (r)
		return (manage_error(r));
	if (lunch_starter(&rules))
		return (throw_error("Error while creating the threads"));
	free(rules.forks);
	free(rules.philos);
	return (0);
}
