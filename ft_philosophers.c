/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:15:50 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/15 20:01:45 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_g_data	*gen_dt;

	ft_check_arguments(argc, argv, 0);
	gen_dt = malloc(sizeof(t_g_data));
	if (gen_dt == NULL)
		exit(0);
	gen_dt->philo_dt = malloc(sizeof(t_philo_data) * ft_atoi(argv[1]));
	if (gen_dt->philo_dt == NULL)
	{
		free(gen_dt);
		exit(0);
	}
	ft_init_v(gen_dt, argv);
	ft_init_threads(gen_dt);
	ft_join_threads(gen_dt);
	ft_free_all(gen_dt);
	return (0);
}

void	ft_print_dead(t_g_data *gen_dt)
{
	printf("philosopher %d is dead in time %lld\n",
		gen_dt->philo_dt[gen_dt->i].id, time_stamp()
		- gen_dt->philo_dt[gen_dt->i].st_time);
}

void	ft_print_philo(t_philo_data	*philo_dt, int mode)
{
	if (mode == 0)
	{
		printf("%lldms philosopher %d has taken a fork\n",
			time_stamp() - philo_dt->st_time, philo_dt->id);
	}
	if (mode == 1)
	{
		printf("%dms philosopher %d is eating\n",
			philo_dt->last_eat, philo_dt->id);
	}
	if (mode == 2)
	{
		printf("%lldms philosopher %d is sleep\n",
			time_stamp() - philo_dt->st_time, philo_dt->id);
	}
	if (mode == 3)
	{
		printf("%lldms philosopher %d is thinking\n",
			time_stamp() - philo_dt->st_time, philo_dt->id);
	}
}
