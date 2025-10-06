/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:03:20 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/06 15:02:39 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	check_fork_avalable(t_philo *philo)
{
	if (get_data_mutex(&philo->left_fork->avalable) == 1
		&& philo->left_fork->id_fork != 0)
	{
		set_data_mutex(&philo->left_fork->avalable, 0);
		set_data_mutex(&philo->left_fork->locked_by, philo->philo_id);
		mutex_print(philo, "has taken a fork");
	}
	if (get_data_mutex(&philo->right_fork->avalable) == 1
		&& philo->right_fork->id_fork != 0)
	{
		set_data_mutex(&philo->right_fork->avalable, 0);
		set_data_mutex(&philo->right_fork->locked_by, philo->philo_id);
		mutex_print(philo, "has taken a fork");
	}
	if (get_data_mutex(&philo->left_fork->avalable) == 0
		&& get_data_mutex(&philo->right_fork->avalable) == 0)
		return (can_eat(philo));
	return (0);
}

void	is_thinking(t_philo *philo)
{
	mutex_print(philo, "is thinking");
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (check_fork_avalable(philo))
		{
			philo->dead_line = time_since_launch(philo->common)
				+ philo->common->time_to_die;
			break ;
		}
		if (time_since_launch(philo->common) >= philo->dead_line)
		{
			set_data_mutex(&philo->common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		usleep(500);
	}
}

void	is_sleeping(t_philo *philo)
{
	mutex_print(philo, "is sleeping");
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (time_since_launch(philo->common) >= philo->dead_line)
		{
			set_data_mutex(&philo->common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		if (time_since_launch(philo->common) >= philo->end_of_sleeping)
			return ;
		usleep(500);
	}
}
