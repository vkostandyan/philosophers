/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:14:33 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/17 17:59:51 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int num_eaten;
    size_t philo_nmb;
    size_t die_time;
    size_t eat_time;
    size_t sleep_time;
    ssize_t must_eat;
    size_t last_eat_time;
    size_t start_time;
    int is_dead;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;

    pthread_mutex_t write_lock;
    pthread_mutex_t num_eaten_lock;
    pthread_mutex_t die_lock;
}               t_philo;

typedef struct s_data
{
    size_t philo_nmb;
    size_t die_time;
    size_t eat_time;
    size_t sleep_time;
    ssize_t must_eat;
    
    // int is_dead;
    t_philo *philo;
    pthread_mutex_t *forks;
    // size_t start_time;
}           t_data;

//---- Validation ----
int	correct_input(int argc, char **argv, t_data *data);

//---- Initialization ----
void init_data(t_data *data);
int memory_allocation(t_data *data);
void clean_data(t_data *data);

//---- Thread ----
int create_thread(t_data *data);

//---- Actions ----
void _sleep(t_philo *philo);
void think(t_philo *philo);
void eat(t_philo *philo);
int is_dead(t_philo *philo);


//---- Helpers ----
size_t get_current_time();
// void	ft_usleep(size_t miliseconds, t_data *data);
void	ft_usleep(size_t miliseconds);
void print_message(t_philo *philo, char *str);

#endif