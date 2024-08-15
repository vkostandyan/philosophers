/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:54:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/15 19:54:56 by vkostand         ###   ########.fr       */
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
	if (!memory_allocation(&data))
	{
		// system("leaks philo");
		return (1);
	}
	if (!init_data(&data))
	{
		printf("Init_data error\n");
		// system("leaks philo");
		return (1);
	}
	if (!create_threads(&data))
	{
		printf("create_threads Error\n");
		// system("leaks philo");
		return (1);
	}
	while (monitoring(&data))
		;
	if (!join_threads(&data))
	{
		printf("join_threads Error \n");
		// system("leaks philo");
		return (1);
	}
	if (!clean_data(&data))
	{
		printf("Clean data Error\n");
		// system("leaks philo");
		return (1);
	}
	// system("leaks philo");
	return (0);
}
