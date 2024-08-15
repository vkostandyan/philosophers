/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:08 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/15 19:43:33 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	memory_allocation(t_data *data)
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

int	clean_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			return (0);
		if (pthread_mutex_destroy(&data->philo[i].write_lock) != 0)
			return (0);
		if (pthread_mutex_destroy(&data->philo[i].num_eaten_lock) != 0)
			return (0);
		if (pthread_mutex_destroy(&data->philo[i].die_lock) != 0)
			return (0);
		if (pthread_mutex_destroy(&data->philo[i].time_lock) != 0)
			return (0);
		i++;
	}
	free(data->philo);
	free(data->forks);
	return (1);
}
