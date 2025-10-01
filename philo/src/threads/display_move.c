/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/01 10:29:52 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	display_philo(t_philo *philo)
{
	gettimeofday(&philo->common->tv, NULL);
	printf("%ld ", philo->common->tv.tv_usec);
	printf("%d ", philo->philo_id);
}

void	philo_action(t_philo *philo)
{
	if (get_data_mutex(&philo->common->stop) == 0)
		is_thinking(philo);
	if (get_data_mutex(&philo->common->stop) == 0)
		taking_fork(philo);
	if (get_data_mutex(&philo->common->stop) == 0)
		is_eating(philo);
	if (get_data_mutex(&philo->common->stop) == 0)
		is_sleeping(philo);
	// if (get_data_mutex(&philo->common->stop) == 0)
	// 	is_dead(philo);
}

void	display_action(t_philo *philo)
{
	philo_action(philo);
}
