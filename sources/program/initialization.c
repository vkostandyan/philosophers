/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:56:12 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 15:34:23 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_philos(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        data->philo[i].id = i + 1;
        data->philo[i].num_eaten = 0;
        data->philo[i].last_meal = get_current_time();
        data->philo[i].l_fork = &data->forks[i];
        if (i == 0)
			data->philo[i].r_fork = &data->forks[data->philo_nmb - 1];
		else
			data->philo[i].r_fork = &data->forks[i - 1];
        if(pthread_mutex_init(&data->philo[i].last_meal_lock, NULL) != 0)
            return (0);
        if(pthread_mutex_init(&data->philo[i].num_eaten_lock, NULL) != 0)
            return (0);
        if(pthread_mutex_init(&data->philo[i].write_lock, NULL) != 0)
            return (0);
        data->philo[i].data = data;
        i++;
    }
    return (1);
}

int init_forks(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        if(pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}

int init_data(t_data *data)
{
    // if(pthread_mutex_init(&data->write_lock, NULL) != 0)
    //         return (0);
    if(pthread_mutex_init(&data->ready_lock, NULL) != 0)
            return (0);
    if(pthread_mutex_init(&data->time_lock, NULL) != 0)
            return (0);
    if(pthread_mutex_init(&data->die_lock, NULL) != 0)
        return (0);
    if(pthread_mutex_init(&data->get_lock, NULL) != 0)
        return (0);
    if(!init_forks(data))
        return (0);
    if(!init_philos(data))
        return (0);
    data->dead_flag = 0;
    data->all_ready = 0;
    data->start_time = get_current_time();
    return (1);
}
