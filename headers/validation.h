/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:45:01 by vkostand          #+#    #+#             */
/*   Updated: 2024/07/13 13:22:04 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct s_input
{
    size_t philo_nmb;
    size_t die_time;
    size_t eat_time;
    size_t sleep_time;
    ssize_t must_eat;
}           t_input;


#endif