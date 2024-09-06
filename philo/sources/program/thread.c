/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:43:11 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 17:33:33 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	wait_for_all_philos(philo);
	if (philo->id % 2 == 0)
		ft_usleep(get_value(&(philo->data->get_lock), &(philo->data->eat_time)),
			philo);
	while (!get_value(&(philo->data->die_lock), &(philo->data->dead_flag)))
	{
		eat(philo);
		_sleep(philo);
		think(philo);
	}
	return (pointer);
}

int	create_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &philo_routine,
				&data->philo[i]) == -1)
			return (0);
		i++;
	}
	pthread_mutex_lock(&data->ready_lock);
	data->all_ready = 1;
	data->start_time = get_current_time();
	pthread_mutex_unlock(&data->ready_lock);
	return (1);
}

int	join_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_nmb)
	{
		if (pthread_join(data->philo[i].thread, NULL) == -1)
			return (0);
		i++;
	}
	return (1);
}
