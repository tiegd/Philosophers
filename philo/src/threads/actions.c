/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/26 14:03:45 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	is_thinking(t_philo *philo)
{
	// while (get_data_mutex())
	display_philo(philo);
	printf("is thinking\n");
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
