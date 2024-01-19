/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:08:49 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/15 20:09:05 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_dead(void *arg)
{
	t_g_data	*gen_dt;

	gen_dt = (t_g_data *)arg;
	while (gen_dt->bdead == 0)
	{
		gen_dt->i = 0;
		while (gen_dt->i < gen_dt->philo && gen_dt->bdead == 0)
		{
			pthread_mutex_lock(&(gen_dt->mutex_dead));
			if (gen_dt->philo_dt[gen_dt->i].eat == gen_dt->must_eat)
			{
				pthread_mutex_unlock(&(gen_dt->mutex_dead));
				return (NULL);
			}
			if (time_stamp() - gen_dt->philo_dt[gen_dt->i].st_time
				- gen_dt->philo_dt[gen_dt->i].last_eat > gen_dt->die_time)
			{
				ft_print_dead(gen_dt);
				gen_dt->bdead = 1;
			}
			pthread_mutex_unlock(&(gen_dt->mutex_dead));
			gen_dt->i++;
		}
	}
	return (NULL);
}

void	ft_init_threads(t_g_data	*gen_dt)
{
	int	i;

	i = 0;
	while (i < gen_dt->philo)
	{
		gen_dt->philo_dt[i].id = i + 1;
		gen_dt->philo_dt[i].gen_dt = gen_dt;
		gen_dt->philo_dt[i].state = 0;
		gen_dt->philo_dt[i].eat = 0;
		gen_dt->philo_dt[i].last_eat = 0;
		if (gen_dt->philo_dt[i].id % 2 != 0)
			gen_dt->philo_dt[i].state = 1;
		gen_dt->philo_dt[i].st_time = time_stamp();
		if (pthread_create(&gen_dt->philo_dt[i].thread, NULL,
				&ft_threads, &(gen_dt->philo_dt[i])) != 0)
			exit(1);
		i++;
	}
	if (pthread_create(&gen_dt->gen_thread, NULL, &ft_check_dead, gen_dt) != 0)
		exit(1);
}

void	*ft_threads(void *arg)
{
	t_philo_data	*philo_dt;

	philo_dt = (t_philo_data *)arg;
	pthread_mutex_init(&philo_dt->mutex, NULL);
	philo_dt->bphilo = 0;
	if (philo_dt->state == 0)
		ft_usleep(philo_dt->gen_dt->eat_time / 2);
	while ((philo_dt->eat < philo_dt->gen_dt->must_eat
			|| philo_dt->gen_dt->must_eat < 0))
	{
		pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
		if (philo_dt->gen_dt->bdead == 0)
		{
			pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
			ft_left_fork(philo_dt);
			ft_right_forks(philo_dt);
		}
		else
		{
			pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
			return (NULL);
		}
	}
	return (NULL);
}

void	ft_join_threads(t_g_data	*gen_dt)
{
	int	i;

	i = 0;
	while (i < gen_dt->philo)
	{
		if (pthread_join(gen_dt->philo_dt[i].thread, NULL) != 0)
			exit(1);
		pthread_mutex_destroy(&gen_dt->philo_dt->mutex);
		i++;
	}
	if (pthread_join(gen_dt->gen_thread, NULL) != 0)
		exit(1);
}
