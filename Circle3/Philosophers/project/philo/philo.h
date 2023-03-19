/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:30:17 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/19 23:51:13 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philos
{
	int					id;
	int					p_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}						t_philos;

typedef struct s_rules
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					is_dead;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
	t_philos			*philos;
}						t_rules;

int			manage_error(int err_no);
int			throw_error(char *str);

int			init_philos(t_rules *rules, char **argv);

int			lunch_starter(t_rules *rules);

int			ft_atoi(const char *str);
long long	get_timestamp(void);
long long	get_time_diff(long long past, long long curr);
void		philo_sleep(long long time, t_rules *rules);
void		current_action(t_rules *rules, int id, char *s);

#endif