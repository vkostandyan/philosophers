/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:14:33 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 18:31:44 by vkostand         ###   ########.fr       */
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

# define PHILO 1
# define DIE 2
# define EAT 3
# define SLEEP 4

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct					s_philo
{
	pthread_t			thread;
	int					id;
	int					num_eaten;
	size_t				last_meal;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		num_eaten_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		last_meal_lock;
	t_data				*data;
};

struct					s_data
{
	size_t				dead_flag;
	size_t				philo_nmb;
	size_t				die_time;
	size_t				eat_time;
	size_t				sleep_time;
	size_t				all_ready;
	size_t				start_time;
	ssize_t				must_eat;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		time_lock;
	pthread_mutex_t		die_lock;
	pthread_mutex_t		get_lock;
	pthread_mutex_t		ready_lock;
	t_philo				*philo;
	pthread_mutex_t		*forks;
};

//---- Validation ----
int						correct_input(int argc, char **argv, t_data *data);
int						all_numbers(int argc, char **argv);
size_t					ft_atos(const char *str);

//---- Helpers ----
void					print_message(t_philo *philo, char *str, int end);
size_t					get_value(pthread_mutex_t *mutex, size_t *value);
void					ft_usleep(size_t sleep_time, t_philo *philo);
void					wait_for_all_philos(t_philo *philo);
size_t					get_current_time(void);

//---- Initialization ----
int						init_philos(t_data *data);
int						init_forks(t_data *data);
int						init_data(t_data *data);

//---- Memory ----
int						allocate_memory(t_data *data);
int						destroy_philos(t_data *data);
int						destroy_forks(t_data *data);
int						clean_memory(t_data *data);

//---- Monitoring
void					change_philo_state(t_data *data);
int						philos_are_full(t_data *data);
int						monitoring(t_data *data);

//---- Actions ----
void					_sleep(t_philo *philo);
void					think(t_philo *philo);
void					eat(t_philo *philo);

//---- Thread ----
void					*philo_routine(void *pointer);
int						create_threads(t_data *data);
int						join_threads(t_data *data);

#endif