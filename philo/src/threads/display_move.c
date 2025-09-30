/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/30 16:37:38 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	display_philo(t_philo *philo)
{
	// gettimeofday(&philo->common->tv, &philo->common->tz);
	gettimeofday(&philo->common->tv, NULL);
	printf("%ld ", philo->common->tv.tv_usec);
	printf("%d ", philo->philo_id);
}

void	philo_action(t_philo *philo)
{
	is_thinking(philo);
	taking_fork(philo);
	is_eating(philo);
	is_sleeping(philo);
	is_dead(philo);
}

void	display_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->stop.mutex);
	philo_action(philo);
	pthread_mutex_unlock(&philo->common->stop.mutex);
}
