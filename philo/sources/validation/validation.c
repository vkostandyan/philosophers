/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:46:07 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 17:32:02 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_atos(const char *str)
{
	int		i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	all_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	correct_input(int argc, char **argv, t_data *philo)
{
	if (!all_numbers(argc, argv))
	{
		printf("Incorrect input\n");
		return (0);
	}
	philo->philo_nmb = ft_atos(argv[1]);
	philo->die_time = ft_atos(argv[2]);
	philo->eat_time = ft_atos(argv[3]);
	philo->sleep_time = ft_atos(argv[4]);
	if (argc == 6)
		philo->must_eat = ft_atos(argv[5]);
	else
		philo->must_eat = -1;
	if (philo->philo_nmb < 1 || philo->die_time < 60
		|| philo->die_time > INT_MAX || philo->eat_time < 60
		|| philo->eat_time > INT_MAX || philo->sleep_time < 60
		|| philo->sleep_time > INT_MAX || philo->must_eat > INT_MAX
		|| (philo->must_eat < 1 && philo->must_eat != -1))
	{
		printf("Incorrect input\n");
		return (0);
	}
	return (1);
}
