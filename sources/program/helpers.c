/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:42:34 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/17 16:15:38 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_message(t_philo *philo, char *str)
{
	size_t time;

	pthread_mutex_lock(&philo->write_lock);
	time = get_current_time() - philo->start_time;
	printf("%zu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->write_lock);
}

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

void	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = get_current_time();
	while (miliseconds > get_current_time() - start) // && !data->is_dead hanecinq vor data chstana
		;
}


// void	ft_usleep(size_t miliseconds, t_data *data)
// {
// 	size_t	start;

// 	start = get_current_time();
// 	while (miliseconds > get_current_time() - start && !data->is_dead)
// 		;
// }
