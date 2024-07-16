/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:05:38 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/16 22:15:41 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philo_routine(void *pointer)
{
    // t_data *data;

    // data = (t_data *)pointer;
    (void)pointer;
    printf("stexem hopar\n");
    // ft_usleep(10000, data);
    return (NULL);
}

int create_thread(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->philo_nmb)
    {
        if (pthread_create(&data->philo[i].thread, NULL, &philo_routine, NULL) == -1)
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