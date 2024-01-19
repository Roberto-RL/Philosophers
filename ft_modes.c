/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:39:13 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/15 20:09:10 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_and_sleep(t_philo_data	*philo_dt)
{
	pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
	philo_dt->last_eat = time_stamp() - philo_dt->st_time;
	if (philo_dt->gen_dt->bdead != 1)
		ft_print_philo(philo_dt, 1);
	philo_dt->eat++;
	pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
	ft_usleep(philo_dt->gen_dt->eat_time);
	pthread_mutex_unlock(&(philo_dt->gen_dt->philo_dt[philo_dt->id - 1].mutex));
	if (philo_dt->id + 1 <= philo_dt->gen_dt->philo)
		pthread_mutex_unlock(&(philo_dt->gen_dt->philo_dt[philo_dt->id].mutex));
	else
		pthread_mutex_unlock(&(philo_dt->gen_dt->philo_dt[0].mutex));
	pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
	if (philo_dt->gen_dt->bdead != 1)
		ft_print_philo(philo_dt, 2);
	pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
	ft_usleep(philo_dt->gen_dt->sleep_time);
	pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
	if (philo_dt->gen_dt->bdead != 1)
		ft_print_philo(philo_dt, 3);
	pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
}

void	ft_right_forks(t_philo_data	*philo_dt)
{
	if (philo_dt->bphilo == 1)
		return ;
	if (philo_dt->id + 1 <= philo_dt->gen_dt->philo)
	{
		pthread_mutex_lock(&(philo_dt->gen_dt->philo_dt[philo_dt->id].mutex));
		pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
		if (philo_dt->gen_dt->bdead != 1)
			ft_print_philo(philo_dt, 0);
		pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
	}
	else if (!(philo_dt->id + 1 <= philo_dt->gen_dt->philo))
	{
		pthread_mutex_lock(&(philo_dt->gen_dt->philo_dt[0].mutex));
		pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
		if (philo_dt->gen_dt->bdead != 1)
			ft_print_philo(philo_dt, 0);
		pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
	}
	ft_eat_and_sleep(philo_dt);
}

void	ft_left_fork(t_philo_data	*philo_dt)
{
	if (philo_dt->gen_dt->philo == 1)
	{
		philo_dt->bphilo = 1;
		return ;
	}
	pthread_mutex_lock(&(philo_dt->gen_dt->philo_dt[philo_dt->id - 1].mutex));
	pthread_mutex_lock(&(philo_dt->gen_dt->mutex_dead));
	if (philo_dt->gen_dt->bdead != 1)
	{
		printf("%lldms philosopher %d has taken a fork\n",
			time_stamp() - philo_dt->st_time, philo_dt->id);
	}
	pthread_mutex_unlock(&(philo_dt->gen_dt->mutex_dead));
}
