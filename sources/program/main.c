/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:54:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/19 18:01:09 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_data data;

    if(!correct_input(argc, argv, &data))
    {
        system("leaks philo");
        return (1);
    }
    if(!memory_allocation(&data))
    {
        system("leaks philo");  
        return (1);
    }
    init_data(&data);
    if(!create_thread(&data))
    {
        printf("Create thread error\n");
        return (1);
    }
    printf("eku main\n");
    // ft_usleep(10000, &data);
    clean_data(&data); 
    system("leaks philo");
    return (0);
}
