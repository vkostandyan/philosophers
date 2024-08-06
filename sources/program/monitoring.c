/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:48:42 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/06 21:42:35 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void change_philo_state(t_data *data)
{
    size_t i;

    i = 0;
    while(i < data->philo_nmb)
    {
        pthread_mutex_lock(&data->philo[i].die_lock);
        data->philo[i].is_dead = 1;
        pthread_mutex_unlock(&data->philo[i].die_lock);
        i++;
    }
}

int philos_are_full(t_data *data)
{
    size_t i;

    i = 0;
    // printf("%zu\n", i);
    while(i < data->philo_nmb)
    {
        pthread_mutex_lock(&data->philo[i].num_eaten_lock);
        if(data->philo[i].num_eaten < data->must_eat)
        {
            pthread_mutex_unlock(&data->philo[i].num_eaten_lock);
            return(0);
        }
        pthread_mutex_unlock(&data->philo[i].num_eaten_lock);
        i++;
    }
    return (1);
}

void print_data(t_philo *philo)
{
    pthread_mutex_lock(&philo->time_lock);
    printf("%zu\n", philo->last_eat_time);    
    pthread_mutex_unlock(&philo->time_lock);
}

int monitoring(t_data *data)
{
    size_t i;

    i = 0;
    while(i < data->philo_nmb)
    {
        t_philo *philo = data->philo + i;
        print_data(philo);
        // pthread_mutex_lock(&philo->time_lock);
        // printf("%zu\n", philo->last_eat_time);    
        // pthread_mutex_unlock(&philo->time_lock);
        // pthread_mutex_lock(&data->philo[i].time_lock);
        // pthread_mutex_unlock(&data->philo[i].time_lock);
        // printf("%zu\n", data->philo[i].last_eat_time);
        // if(get_current_time() - data->philo[i].last_eat_time >= data->die_time)   
        // {
        //     change_philo_state(data);
        //     print_message(&data->philo[i], "died");
        //     pthread_mutex_unlock(&data->philo[i].time_lock);
        //     return (0);
        // }
        // pthread_mutex_unlock(&data->philo[i].time_lock);
        i++;
    }
    return (0);
}



// if(philos_are_full(data) || philo_is_dead(data))
//         {
//             change_philo_state(data);
//             return (0);
//         }
