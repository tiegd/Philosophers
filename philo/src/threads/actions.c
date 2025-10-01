/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/01 13:48:06 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	is_thinking(t_philo *philo)
{
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (philo->is_thinking == 0)
		{
			printf("%ld %d is thinking\n", philo->common->tv.tv_usec, philo->philo_id);
			philo->is_thinking = 1;
		}
		if (check_fork_avalable(philo))
		{
			philo->is_thinking = 0;
			philo->dead_line = philo->common->tv.tv_usec + philo->common->time_to_die;
			break;
		}
		if (philo->common->tv.tv_usec >= philo->dead_line)
		{
			// display_philo(philo);
			set_data_mutex(&philo->common->stop, 1);
			printf("%ld %d is dead\n", philo->common->tv.tv_usec, philo->philo_id);
			break;
		}
		usleep(450);
	}
}

int	check_fork_avalable(t_philo *philo)
{
	// if (philo->left_fork->avalable.data == 1)
	if (get_data_mutex(&philo->left_fork->avalable) == 1)
	{
		pthread_mutex_lock(&philo->left_fork->avalable.mutex);
		philo->left_fork->avalable.data = 0;
		printf(RED"%ld %d has taken a fork %d\n"RESET, philo->common->tv.tv_usec, philo->philo_id, philo->left_fork->id_fork);
	}
	// if (philo->right_fork->avalable.data == 1)
	if (get_data_mutex(&philo->right_fork->avalable) == 1)
	{
		pthread_mutex_lock(&philo->right_fork->avalable.mutex);
		philo->right_fork->avalable.data = 0;
		printf(GREEN"%ld %d has taken a fork %d\n"RESET, philo->common->tv.tv_usec, philo->philo_id, philo->right_fork->id_fork);
	}
	if (philo->left_fork->avalable.data == 0 && philo->right_fork->avalable.data == 0)
	{
		philo->last_meal = philo->common->tv.tv_usec;
		philo->end_of_meal = philo->last_meal + philo->common->time_to_eat;
		return (1);
	}
	return (0);
}

void	is_eating(t_philo *philo)
{
	printf("%ld %d is eating\n", philo->common->tv.tv_usec, philo->philo_id);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (philo->common->tv.tv_sec == philo->end_of_meal)
		{
			philo->left_fork->avalable.data = 1;
			philo->right_fork->avalable.data = 1;
			pthread_mutex_unlock(&philo->left_fork->avalable.mutex);
			pthread_mutex_unlock(&philo->right_fork->avalable.mutex);
			philo->end_of_sleeping = philo->common->tv.tv_usec + philo->common->time_to_sleep;
			break;
		}
		usleep(500);
	}
}

void	is_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", philo->common->tv.tv_usec, philo->philo_id);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (philo->common->tv.tv_usec == philo->end_of_sleeping)
			return;
	}
}
