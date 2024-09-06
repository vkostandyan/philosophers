/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:27:45 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 17:33:29 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday error\n", 19);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t sleep_time, t_philo *philo)
{
	u_int64_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < sleep_time
		&& !get_value(&(philo->data->die_lock), &(philo->data->dead_flag)))
		usleep(500);
}

void	print_message(t_philo *philo, char *str, int end)
{
	pthread_mutex_lock(&philo->write_lock);
	if (!get_value(&(philo->data->die_lock), &(philo->data->dead_flag))
		|| end == 1)
		printf("%zu %d %s\n", get_current_time() - philo->data->start_time,
			philo->id, str);
	pthread_mutex_unlock(&philo->write_lock);
}

size_t	get_value(pthread_mutex_t *mutex, size_t *value)
{
	size_t	temp;

	pthread_mutex_lock(mutex);
	temp = *value;
	pthread_mutex_unlock(mutex);
	return (temp);
}

void	wait_for_all_philos(t_philo *philo)
{
	while (!get_value(&(philo->data->ready_lock), &philo->data->all_ready))
		;
}
