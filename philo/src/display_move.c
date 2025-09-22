/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 13:08:29 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

void    display_philo(t_philo *philo)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	printf("%ld ", tv.tv_usec);
    printf("%d ", philo->philo_id);
}

void    display_move(t_philo *philo)
{
    pthread_mutex_lock(&philo->common->common_mutex);
    display_philo(philo);
    printf("\n");
    pthread_mutex_unlock(&philo->common->common_mutex);
}

// int taken_a_fork(int philo_id)
// {
    
// }

// int is_eating()
// {
    
// }

// int is_sleeping()
// {
    
// }

// int is_thinking()
// {
    
// }

// int died()
// {
    
// }
