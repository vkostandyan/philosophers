/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:18:58 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/16 18:36:53 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_data(t_data *data)
{
    size_t i;

    i = 0;
    data->start_time = get_current_time();
    data->is_dead = 0;
    while (i < data->philo_nmb)
    {
        data->philo[i].id = i + 1;
        data->philo[i].num_eaten = 0;
        data->philo[i].last_eat_time = get_current_time();
        data->philo[i].l_fork = &data->forks[i];
        if(i == 0)
            data->philo[i].r_fork = &data->forks[data->philo_nmb - 1];
        else
            data->philo[i].r_fork = &data->forks[i - 1];
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
}

