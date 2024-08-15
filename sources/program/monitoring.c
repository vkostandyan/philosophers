/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:48:42 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/15 19:48:57 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	change_philo_state(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		pthread_mutex_lock(&data->philo[i].die_lock);
		data->philo[i].is_dead = 1;
		pthread_mutex_unlock(&data->philo[i].die_lock);
		i++;
	}
}

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

int	monitoring(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		if (philos_are_full(data))
		{
			change_philo_state(data);
			printf("Everyone is full\n");
			return (0);
		}
		pthread_mutex_lock(&data->philo[i].time_lock);
		if (get_current_time() - data->philo[i].last_eat_time >= data->die_time)
		{
			change_philo_state(data);
			print_message(&data->philo[i], "died", 1);
			pthread_mutex_unlock(&data->philo[i].time_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->philo[i].time_lock);
		i++;
	}
	return (1);
}
