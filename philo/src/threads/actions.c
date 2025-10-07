/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 09:14:41 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	check_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->avalable.mutex);
	if (philo->left_fork->avalable.data == 1)
	{
		philo->left_fork->avalable.data = 0;
		mutex_print(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->left_fork->avalable.mutex);
}

void	check_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->avalable.mutex);
	if (philo->right_fork->avalable.data == 1)
	{
		philo->right_fork->avalable.data = 0;
		mutex_print(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->right_fork->avalable.mutex);
}

static int	check_fork_avalable(t_philo *philo)
{
	check_left(philo);
	check_right(philo);
	if (get_data_mutex(&philo->left_fork->avalable) == 0
		&& get_data_mutex(&philo->right_fork->avalable) == 0)
		return (can_eat(philo));
	return (0);
}

void	is_thinking(t_philo *philo, int init)
{
	t_common	*common;

	common = philo->common;
	if (init == 1)
		mutex_print(philo, "is thinking");
	while (get_data_mutex(&common->stop) == 0)
	{
		if (check_fork_avalable(philo))
		{
			philo->dead_line = time_since_launch(common)
				+ common->time_to_die;
			break ;
		}
		if (time_since_launch(common) >= philo->dead_line)
		{
			set_data_mutex(&common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		usleep(500);
	}
}

void	is_sleeping(t_philo *philo)
{
	t_common	*common;

	common = philo->common;
	mutex_print(philo, "is sleeping");
	while (get_data_mutex(&common->stop) == 0)
	{
		if (time_since_launch(common) >= philo->dead_line)
		{
			set_data_mutex(&common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		if (time_since_launch(common) >= philo->end_of_sleeping)
			return ;
		usleep(500);
	}
}
