/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/01 10:26:19 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	is_thinking(t_philo *philo)
{
	printf("paul le poulpe\n");
	printf("philo->common->stop = %d\n", philo->common->stop.data);
	while (get_data_mutex(&philo->common->stop) == 0)
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
			set_data_mutex(&philo->common->stop, 1);
			printf("died\n");
			break;
		}
		printf("simon la mouche\n");
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
