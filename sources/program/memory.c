/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:08 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/16 21:20:52 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int memory_allocation(t_data *data)
{
    data->philo = (t_philo *)malloc((sizeof(t_philo)) * data->philo_nmb);
    if(!data->philo)
    {
        printf("philo malloc error\n");
        return(0);
    }
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_nmb); 
    if(!data->forks)
    {
        free(data->philo);
        printf("fork malloc error\n");
        return (0);
    }
    return (1);
}

void clean_data(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        pthread_mutex_destroy(&data->forks[i]);
        // pthread_join(data->philo[i].thread, NULL); // texapoxeci threadi mej
        i++;
    }
    free(data->philo);
    free(data->forks);
}
