/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:58:13 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/11 20:15:46 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_all(t_g_data	*gen_dt)
{
	pthread_mutex_destroy(&gen_dt->mutex_dead);
	free(gen_dt->philo_dt);
	free(gen_dt);
}
