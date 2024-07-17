/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:54:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/17 21:57:27 by vkostand         ###   ########.fr       */
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
        printf("Chem kracal \n");
    }
    // ft_usleep(10000, &data);
    clean_data(&data); 
    system("leaks philo");
    return (0);
}
