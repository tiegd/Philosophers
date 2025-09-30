/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/30 16:29:37 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	is_thinking(t_philo *philo)
{
	printf("paul le poulpe\n");
	printf("philo->common->stop = %d\n", philo->common->stop.data);
	// printf("get_datat : philo->common->stop = %d\n", get_data_mutex(&philo->common->stop));
	// while (get_data_mutex(&philo->common->stop) == 0)
	while (philo->common->stop.data == 0)
	{
		printf("laala\n");
		printf("time = %ld\ndead_line = %d\n", philo->common->tv.tv_usec, philo->dead_line);
		if (philo->is_thinking == 0)
		{
			display_philo(philo);
			printf("is thinking\n");
			philo->is_thinking = 1;
		}
		if (philo->common->tv.tv_usec >= philo->dead_line)
		{
			display_philo(philo);
			printf("died\n");
			set_data_mutex(&philo->common->stop, 1);
			break;
		}
		usleep(500);
	}
}

void	taking_fork(t_philo *philo)
{
	display_philo(philo);
	printf("has taking a fork\n");
}

void	is_eating(t_philo *philo)
{
	display_philo(philo);
	printf("is eating\n");
}

void	is_sleeping(t_philo *philo)
{
	display_philo(philo);
	printf("is sleeping\n");
}

void	is_dead(t_philo *philo)
{
	display_philo(philo);
	printf("is dead\n");
}
