/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 16:33:32 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

void	display_philo(t_philo *philo)
{
	gettimeofday(&philo->common->tv, &philo->common->tz);
	printf("%ld ", philo->common->tv.tv_usec);
	printf("%d ", philo->philo_id);
}

void	philo_action(t_philo *philo)
{
	philo->end_of_eating = philo->last_meal + philo->common->time_to_eat;
	philo->end_of_sleeping = philo->end_of_eating + philo->common->time_to_sleep;
	// printf("philo[%d] --> end_of_eating = %d\nphilo[%d] --> end_of_sleeping = %d\n", philo->philo_id, philo->end_of_eating, philo->philo_id, philo->end_of_sleeping);
	if (philo->right_fork == 1 && philo->left_fork == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		
	}
}

void	display_move(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->common_mutex);
	display_philo(philo);
	philo_action(philo);
	printf("\n");
	pthread_mutex_unlock(&philo->common->common_mutex);
}
