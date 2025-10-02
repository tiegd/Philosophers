/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/02 14:13:50 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	philo_action(t_philo *philo)
{
	// gettimeofday(&philo->common->tv, NULL);
	// if (philo->philo_id % 2 != 0)
	// {
	// 	printf(RED"philo %d is waiting\n"RESET, philo->philo_id);
	// 	usleep(philo->common->time_to_eat / 2);
	// }
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (get_data_mutex(&philo->common->stop) == 0)
			is_thinking(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_eating(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_sleeping(philo);
		usleep(400);
	}
}
