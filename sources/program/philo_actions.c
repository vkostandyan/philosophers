/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:52:08 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 15:34:50 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	_sleep(t_philo *philo)
{
	if (get_value(&(philo->data->die_lock), &(philo->data->dead_flag)))
		return ;
	print_message(philo, "is sleeping", 0);
	ft_usleep(philo->data->sleep_time, philo);
}

void	think(t_philo *philo)
{
	if (get_value(&(philo->data->die_lock), &(philo->data->dead_flag)))
		return ;
	print_message(philo, "is thinking", 0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, "has taken a fork", 0);
	if (philo->data->philo_nmb == 1)
	{
		ft_usleep(philo->data->die_time, philo);
		pthread_mutex_lock(&philo->data->die_lock);
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->die_lock);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->last_meal_lock);
	pthread_mutex_lock(&philo->num_eaten_lock);
	print_message(philo, "is eating", 0);
	philo->num_eaten++;
	pthread_mutex_unlock(&philo->num_eaten_lock);
	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
