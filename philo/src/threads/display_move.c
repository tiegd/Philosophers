/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/01 19:08:28 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// void	display_philo(t_philo *philo)
// {
// 	gettimeofday(&philo->common->tv, NULL);
// 	printf("%ld ", philo->common->tv.tv_usec);
// 	printf("%d ", philo->philo_id);
// }

void	philo_action(t_philo *philo)
{
	gettimeofday(&philo->common->tv, NULL);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		printf(YELLOW"philo nb %d\n"RESET, philo->philo_id);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_thinking(philo);
		printf(YELLOW"philo nb %d finish thinking\n"RESET, philo->philo_id);
		// if (get_data_mutex(&philo->common->stop) == 0)
		// 	taking_fork(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_eating(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_sleeping(philo);
		// if (get_data_mutex(&philo->common->stop) == 0)
		// 	is_dead(philo);
		usleep(400);
	}
}
