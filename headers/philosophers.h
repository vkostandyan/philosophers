/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:14:33 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/15 19:50:56 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				num_eaten;
	size_t			philo_nmb;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	ssize_t			must_eat;
	size_t			last_eat_time;
	size_t			start_time;
	int				is_dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;

	pthread_mutex_t	write_lock;
	pthread_mutex_t	num_eaten_lock;
	pthread_mutex_t	die_lock;
	pthread_mutex_t	time_lock;
}					t_philo;

typedef struct s_data
{
	size_t			philo_nmb;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	ssize_t			must_eat;

	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_data;

//---- Validation ----
int					correct_input(int argc, char **argv, t_data *data);
int					all_numbers(int argc, char **argv);
size_t				ft_atos(const char *str);

//---- Helpers ----
size_t				get_current_time(void);
void				ft_usleep(size_t miliseconds);
void				print_message(t_philo *philo, char *str, int end);

//---- Initialization ----
int					init_data(t_data *data);
int					mutex_init(t_data *data, size_t i);

//---- Memory ----
int					memory_allocation(t_data *data);
int					clean_data(t_data *data);

//---- Monitoring
int					monitoring(t_data *data);
void				change_philo_state(t_data *data);
int					philos_are_full(t_data *data);

//---- Actions ----
void				_sleep(t_philo *philo);
void				think(t_philo *philo);
void				eat(t_philo *philo);
int					is_dead(t_philo *philo);

//---- Thread ----
int					create_threads(t_data *data);
int					join_threads(t_data *data);
void				*philo_routine(void *pointer);

#endif