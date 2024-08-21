/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:58:29 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 15:37:12 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_are_full(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->must_eat == -1)
		return (0);
	while (i < data->philo_nmb)
	{
		pthread_mutex_lock(&data->philo[i].num_eaten_lock);
		if (data->philo[i].num_eaten < data->must_eat)
		{
			pthread_mutex_unlock(&data->philo[i].num_eaten_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->philo[i].num_eaten_lock);
		i++;
	}
	return (1);
}

void change_philos_state(t_data *data)
{
    pthread_mutex_lock(&data->die_lock);
    data->dead_flag = 1;
    pthread_mutex_unlock(&data->die_lock);
}

int	monitoring(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		if (philos_are_full(data))
		{
			change_philos_state(data);
			printf("Everyone is full\n");
			return (0);
		}
		pthread_mutex_lock(&data->time_lock);
		// get_value(&(data->philo[i].last_meal_lock), &(data->philo[i].last_meal))
		if (get_current_time() - get_value(&(data->philo[i].last_meal_lock), &(data->philo[i].last_meal)) >= get_value(&(data->get_lock), &(data->die_time)))
		{
			change_philos_state(data);
			print_message(&data->philo[i], "died", 1);
			pthread_mutex_unlock(&data->time_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->time_lock);
		i++;
	}
	return (1);
}
