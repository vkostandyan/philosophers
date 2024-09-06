/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:33:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/08/21 16:05:11 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!correct_input(argc, argv, &data))
		return (1);
	if (!allocate_memory(&data))
		return (2);
	if (!init_data(&data))
		return (clean_memory(&data));
	if (!create_threads(&data))
		return (clean_memory(&data));
	while (monitoring(&data))
		;
	if (!join_threads(&data))
		return (clean_memory(&data));
	if (!clean_memory(&data))
		return (3);
	return (0);
}
