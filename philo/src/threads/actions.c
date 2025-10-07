/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 11:14:33 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static void	check_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->avalable.mutex);
	if (philo->left_fork->avalable.data == 1)
	{
		philo->left_fork->avalable.data = 0;
		philo->fork_left_av = 1;
		mutex_print(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->left_fork->avalable.mutex);
}

static void	check_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->avalable.mutex);
	if (philo->right_fork->avalable.data == 1)
	{
		philo->right_fork->avalable.data = 0;
		philo->fork_right_av = 1;
		mutex_print(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->right_fork->avalable.mutex);
}

static int	check_fork_avalable(t_philo *philo)
{
	if (philo->fork_left_av == 0)
		check_left(philo);
	if (philo->fork_right_av == 0)
		check_right(philo);
	if (philo->fork_left_av == 1 && philo->fork_right_av == 1)
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
		usleep(400);
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
		usleep(400);
	}
}
