/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:01:01 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/15 19:53:10 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_v(t_g_data	*gen_dt, char **argv)
{
	gen_dt->bdead = 0;
	gen_dt->i = 0;
	gen_dt->philo = ft_atoi(argv[1]);
	gen_dt->die_time = (ft_atoi(argv[2]));
	gen_dt->eat_time = (ft_atoi(argv[3]));
	gen_dt->sleep_time = (ft_atoi(argv[4]));
	if (gen_dt->die_time < 0 || gen_dt->eat_time < 0
		|| gen_dt->sleep_time < 0)
		ft_check_arguments(0, argv, 1);
	if (argv[5] != NULL)
	{
		gen_dt->must_eat = ft_atoi(argv[5]);
		if (gen_dt->must_eat <= 0)
			ft_check_arguments(0, argv, 1);
	}
	else
		gen_dt->must_eat = -1;
	pthread_mutex_init(&gen_dt->mutex_dead, NULL);
}
