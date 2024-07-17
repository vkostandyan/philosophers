/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:05:38 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/17 21:00:06 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philo_routine(void *pointer)
{
    t_philo *philo;

    philo = (t_philo *)pointer;
    if(philo->id % 2 == 0)
        ft_usleep(philo->eat_time);
    while(!is_dead(philo))
    {
        eat(philo);
        _sleep(philo);
        think(philo);
    }
    return (NULL);
}

int create_thread(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        if (pthread_create(&data->philo[i].thread, NULL, &philo_routine, &data->philo[i]) == -1)
            return (0);
        i++;
    }
    i = 0;
    while (i < data->philo_nmb)
    {
        if (pthread_join(data->philo[i].thread, NULL) == -1)
            return (0);
        i++;
    }
    return (1);
}