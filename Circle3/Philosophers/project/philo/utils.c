/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:32:38 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/19 22:10:21 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

long long	get_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	get_time_diff(long long past, long long curr)
{
	return (curr - past);
}

void	philo_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = get_timestamp();
	while (!(rules->is_dead))
	{
		if (get_time_diff(i, get_timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	current_action(t_rules *rules, int id, char *s)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->is_dead))
	{
		printf("%lli ", get_timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(rules->writing));
}
