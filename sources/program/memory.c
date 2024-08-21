/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:47:11 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 15:34:29 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	allocate_memory(t_data *data)
{
	data->philo = (t_philo *)malloc((sizeof(t_philo)) * data->philo_nmb);
	if (!data->philo)
	{
		printf("philo malloc error\n");
		return (0);
	}
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->philo_nmb);
	if (!data->forks)
	{
		free(data->philo);
		printf("fork malloc error\n");
		return (0);
	}
	return (1);
}

int destroy_forks(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        if(pthread_mutex_destroy(&data->forks[i]) != 0)
            return (0);
        i++;
    }
    return (1);
}

int destroy_philos(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        if(pthread_mutex_destroy(&data->philo[i].last_meal_lock) != 0)
            return (0);
        if(pthread_mutex_destroy(&data->philo[i].num_eaten_lock) != 0)
            return (0);
		if(pthread_mutex_destroy(&data->philo[i].write_lock) != 0)
            return (0);
		i++;
    }
	return (1);
}

int clean_memory(t_data *data)
{
	if(!destroy_philos(data))
		return (0);
	if(!destroy_forks(data))
		return (0);
	// if(pthread_mutex_destroy(&data->write_lock) != 0)
    //         return (0);
	if(pthread_mutex_destroy(&data->ready_lock) != 0)
            return (0);
    if(pthread_mutex_destroy(&data->time_lock) != 0)
            return (0);
    if(pthread_mutex_destroy(&data->die_lock) != 0)
            return (0);
    if(pthread_mutex_destroy(&data->get_lock) != 0)
            return (0);
    free(data->forks);
    free(data->philo);
    return (1);
}
