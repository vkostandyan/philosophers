/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:20:46 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/17 19:31:45 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void _sleep(t_philo *philo)
{
    print_message(philo, "is sleeping");
    ft_usleep(philo->sleep_time);
}

void think(t_philo *philo)
{
    print_message(philo, "is thinking");
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_message(philo, "has taken a fork");
    if (philo->philo_nmb == 1)
    {
        ft_usleep(philo->die_time);
        philo->is_dead = 1;
        return ;
    }
    pthread_mutex_lock(philo->r_fork);
    print_message(philo, "has taken a fork");
    pthread_mutex_lock(&philo->num_eaten_lock);
    print_message(philo, "is eating");
    philo->num_eaten++;
    pthread_mutex_unlock(&philo->num_eaten_lock);
    ft_usleep(philo->eat_time);
    philo->last_eat_time = get_current_time();
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->die_lock);
    if(philo->is_dead)
    {
        pthread_mutex_unlock(&philo->die_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->die_lock);
    return (0);
}
