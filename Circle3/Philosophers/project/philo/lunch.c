/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:48:49 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/20 00:45:24 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	feed_philo(t_philos *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	current_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	current_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	current_action(rules, philo->id, "is eating");
	philo->t_last_meal = get_timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	philo_sleep(rules->time_eat, rules);
	(philo->p_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

static void	*eat_sleep_think(void *philos)
{
	t_philos	*philo;
	t_rules		*rules;

	philo = (t_philos *)philos;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->is_dead))
	{
		feed_philo(philo);
		if (rules->all_ate)
			break ;
		current_action(rules, philo->id, "is sleeping");
		philo_sleep(rules->time_sleep, rules);
		current_action(rules, philo->id, "is thinking");
	}
	return (NULL);
}

static void	exit_trigger(t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

static void	is_dead_or_ate(t_rules *r, t_philos *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->is_dead))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (get_time_diff(p[i].t_last_meal,
					get_timestamp()) > r->time_death)
			{
				current_action(r, i, "died");
				r->is_dead = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->is_dead)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].p_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

/*
** lunch_starter function, creates the threads and 
** calls the death checker after the threads are created.
** Also calls the exit_trigger function to 
** free the memory and destroy the mutexes.
** Returns 0 if everything went well, 
** 1 if there was an error.When is_dead_or_ate works, 
** main while loop check all_ate and dieded
** But if define r->nb_eat to positive number, 
** then end when all philo ate if no one died
*/
int	lunch_starter(t_rules *rules)
{
	int	i;

	i = 0;
	rules->first_timestamp = get_timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(rules->philos[i].thread_id),
				NULL, eat_sleep_think, &(rules->philos[i])))
			return (1);
		rules->philos[i].t_last_meal = get_timestamp();
		i++;
	}
	is_dead_or_ate(rules, rules->philos);
	exit_trigger(rules, rules->philos);
	return (0);
}
