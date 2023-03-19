/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:19:38 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/20 00:43:51 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mealers(t_rules *rules)
{
	int	i;

	rules->philos = malloc(sizeof(t_philos) * rules->nb_philo);
	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philos[i].id = i;
		rules->philos[i].p_ate = 0;
		rules->philos[i].left_fork_id = i;
		rules->philos[i].right_fork_id = (i + 1) % rules->nb_philo;
		rules->philos[i].t_last_meal = 0;
		rules->philos[i].rules = rules;
	}
	return (0);
}

static int	init_mtx(t_rules *rules)
{
	int	i;

	rules->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * rules->nb_philo);
	i = rules->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
		{
			free(rules->forks);
			return (1);
		}
	}
	if (pthread_mutex_init(&rules->writing, NULL))
		return (1);
	if (pthread_mutex_init(&rules->meal_check, NULL))
		return (1);
	return (0);
}

int	init_philos(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->all_ate = 0;
	rules->is_dead = 0;
	if (rules->nb_philo < 2 || rules->time_death < 0 || rules->time_eat < 0
		|| rules->time_sleep < 0)
		return (1);
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			return (1);
	}
	else
		rules->nb_eat = -1;
	if (init_mtx(rules))
		return (2);
	init_mealers(rules);
	return (0);
}
