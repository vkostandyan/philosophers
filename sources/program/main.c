/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:33:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 14:59:09 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!correct_input(argc, argv, &data))
	{
		// system("leaks philo");
		return (1);
	}
	if (!allocate_memory(&data))
	{
		// system("leaks philo");
		return (2);
	}
	if (!init_data(&data))
	{
		// system("leaks philo");
		return (3);
	}
	if (!create_threads(&data))
	{
		// system("leaks philo");
		return (4);
	}
	while (monitoring(&data))
		;
	if (!join_threads(&data))
	{
		// system("leaks philo");
		return (5);
	}
	if (!clean_memory(&data))
	{
		// system("leaks philo");
		return (6);
	}
	// system("leaks philo");
	return (0);
}
