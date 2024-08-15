/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:18:58 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/15 19:45:30 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_init(t_data *data, size_t i)
{
	if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo[i].write_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo[i].num_eaten_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo[i].die_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo[i].time_lock, NULL) != 0)
		return (0);
	return (1);
}

int	init_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].num_eaten = 0;
		data->philo[i].start_time = get_current_time();
		data->philo[i].last_eat_time = get_current_time();
		data->philo[i].philo_nmb = data->philo_nmb;
		data->philo[i].is_dead = 0;
		data->philo[i].die_time = data->die_time;
		data->philo[i].eat_time = data->eat_time;
		data->philo[i].sleep_time = data->sleep_time;
		data->philo[i].must_eat = data->must_eat;
		if (!mutex_init(data, i))
			return (0);
		data->philo[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philo[i].r_fork = &data->forks[data->philo_nmb - 1];
		else
			data->philo[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (1);
}
