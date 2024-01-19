/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:26:52 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/15 20:08:45 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>

typedef struct t_g_data
{
	int						i;
	int						alert;
	int						bdead;
	int						count;
	int						philo;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						must_eat;
	int						status;
	struct t_philo_data		*philo_dt;
	pthread_t				gen_thread;
	pthread_mutex_t			mutex_dead;

}	t_g_data;

typedef struct t_philo_data
{
	struct t_g_data	*gen_dt;
	pthread_t		thread;
	int				id;
	int				state;
	int				eat;
	int				last_eat;
	int				bphilo;
	long int		st_time;
	pthread_mutex_t	mutex;
	struct timeval	start_time;
	struct timeval	end_time;

}	t_philo_data;

void		ft_check_arguments(int argc, char **argv, int bmode);
void		ft_init_v(t_g_data	*gen_dt, char **argv);
void		ft_init_threads(t_g_data	*gen_dt);
void		ft_forks(t_philo_data	*philo_dt);
void		ft_take_forks(t_philo_data	*philo_dt, int bmode);
void		ft_eat_and_sleep(t_philo_data	*philo_dt);
void		ft_leave_forks(t_philo_data	*philo_dt);
void		ft_join_threads(t_g_data	*gen_dt);
void		*ft_threads(void *arg);
void		*ft_check_dead(void *arg);
long long	time_stamp(void);
void		ft_usleep(int time_ms);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);
void		ft_free_all(t_g_data	*gen_dt);
void		inicialize_list(t_g_data *g_data);
void		ft_left_fork(t_philo_data	*philo_dt);
void		ft_right_forks(t_philo_data	*philo_dt);
void		ft_print_dead(t_g_data *gen_dt);
void		ft_print_philo(t_philo_data	*philo_dt, int mode);

#endif
