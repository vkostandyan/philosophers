/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:18:58 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/18 22:06:29 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_data(t_data *data)
{
    size_t i;

    i = 0;
    // data->start_time = get_current_time();
    // data->is_dead = 0;
    while (i < data->philo_nmb)
    {
        data->philo[i].id = i + 1;
        data->philo[i].num_eaten = 0;
        data->philo[i].start_time = get_current_time();
        data->philo[i].last_eat_time = get_current_time();
        data->philo[i].philo_nmb = data->philo_nmb;
        data->philo[i].is_dead = 0;
        data->philo[i].die_time = data->die_time;
        data->philo[i].eat_time = data->eat_time;
        data->philo[i].sleep_time = data->sleep_time;
        data->philo[i].must_eat = data->must_eat;
        data->philo[i].l_fork = &data->forks[i];
        if(i == 0)
            data->philo[i].r_fork = &data->forks[data->philo_nmb - 1];
        else
            data->philo[i].r_fork = &data->forks[i - 1];
        pthread_mutex_init(&data->forks[i], NULL);
        pthread_mutex_init(&data->philo->write_lock, NULL);
        pthread_mutex_init(&data->philo->num_eaten_lock, NULL);
        pthread_mutex_init(&data->philo->die_lock, NULL);
        pthread_mutex_init(&data->philo->time_lock, NULL);
        i++;
    }
}

