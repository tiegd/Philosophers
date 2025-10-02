/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/02 17:17:46 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

size_t	get_curent_time(t_common *common)
{
	size_t	time_mili;
	size_t	sec;
	size_t	micro;

	gettimeofday(&common->tv, NULL);
	sec = common->tv.tv_sec * 1000;
	micro = common->tv.tv_usec / 1000;
	time_mili = sec + micro;
	return (time_mili);
}

size_t	time_since_launch(t_common *common)
{
	size_t	curent_time;
	size_t	time_since_launch;

	curent_time = get_curent_time(common);
	// printf(RED"curent_time = %zu\n"RESET, curent_time);
	time_since_launch = curent_time - common->begin_simulation.data;
	// printf(GREEN"time_since_launch = %zu\n"RESET, time_since_launch);
	return (time_since_launch);
}

void	is_thinking(t_philo *philo)
{
	// gettimeofday(&philo->common->tv, NULL);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (philo->is_thinking == 0)
		{
			printf("%zu %d is thinking\n", time_since_launch(philo->common), philo->philo_id);
			philo->is_thinking = 1;
		}
		if (check_fork_avalable(philo))
		{
			philo->is_thinking = 0;
			philo->dead_line = time_since_launch(philo->common) + philo->common->time_to_die;
			break;
		}
		if (time_since_launch(philo->common) >= philo->dead_line)
		{
			set_data_mutex(&philo->common->stop, 1);
			printf(RED"%zu %d is dead\n"RESET, time_since_launch(philo->common), philo->philo_id);
			printf(YELLOW"begin simulation = %zu\n"RESET, philo->common->begin_simulation.data);
			break;
		}
		usleep(500);
	}
}

int	check_fork_avalable(t_philo *philo)
{
	if (get_data_mutex(&philo->left_fork->avalable) == 1)
	{
		set_data_mutex(&philo->left_fork->avalable, 0);
		philo->left_fork->locked_by = philo->philo_id;
		printf("%zu %d has taken a fork\n", time_since_launch(philo->common), philo->philo_id);
	}
	if (get_data_mutex(&philo->right_fork->avalable) == 1)
	{
		set_data_mutex(&philo->right_fork->avalable, 0);
		philo->right_fork->locked_by = philo->philo_id;
		printf("%zu %d has taken a fork\n", time_since_launch(philo->common), philo->philo_id);
	}
	if (get_data_mutex(&philo->left_fork->avalable) == 0 && get_data_mutex(&philo->right_fork->avalable) == 0)
	{
		if (philo->left_fork->locked_by == philo->philo_id && philo->right_fork->locked_by == philo->philo_id)
		{
			// philo->last_meal = philo->common->tv.tv_usec;
			philo->last_meal = time_since_launch(philo->common);
			philo->end_of_meal = philo->last_meal + philo->common->time_to_eat;
			return (1);
		}
	}
	return (0);
}

void	is_eating(t_philo *philo)
{
	printf("%zu %d is eating\n", time_since_launch(philo->common), philo->philo_id);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (time_since_launch(philo->common) >= philo->end_of_meal)
		{
			set_data_mutex(&philo->left_fork->avalable, 1);
			set_data_mutex(&philo->right_fork->avalable, 1);
			philo->left_fork->locked_by = 0;
			philo->right_fork->locked_by = 0;
			// philo->end_of_sleeping = philo->common->tv.tv_usec + philo->common->time_to_sleep;
			philo->end_of_sleeping = time_since_launch(philo->common) + philo->common->time_to_sleep;
			break;
		}
		usleep(500);
	}
}

void	is_sleeping(t_philo *philo)
{
	printf("%zu %d is sleeping\n", time_since_launch(philo->common), philo->philo_id);
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (time_since_launch(philo->common) >= philo->end_of_sleeping)
			return;
		usleep(500);
	}
}
