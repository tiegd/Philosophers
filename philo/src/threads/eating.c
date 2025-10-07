/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:25:34 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 11:53:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	can_eat(t_philo *philo)
{
	if (philo->left_fork->id_fork != philo->right_fork->id_fork)
	{
		philo->last_meal = time_since_launch(philo->common);
		philo->end_of_meal = philo->last_meal
			+ philo->common->time_to_eat;
		return (1);
	}
	return (0);
}

static void	re_init_values(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->avalable.mutex);
	philo->left_fork->avalable.data = 1;
	pthread_mutex_unlock(&philo->left_fork->avalable.mutex);
	pthread_mutex_lock(&philo->right_fork->avalable.mutex);
	philo->right_fork->avalable.data = 1;
	pthread_mutex_unlock(&philo->right_fork->avalable.mutex);
	philo->fork_left_av = 0;
	philo->fork_right_av = 0;
}

static void	count_philo_satiatates(t_philo *philo)
{
	t_common	*common;

	common = philo->common;
	if (philo->common->nb_must_eat >= 0)
	{
		if (philo->nb_meal == common->nb_must_eat)
			set_data_mutex(&common->all_philo_satiated,
				common->all_philo_satiated.data + 1);
		if (get_data_mutex(&common->all_philo_satiated)
			== common->nb_philo)
			set_data_mutex(&common->stop, 1);
	}
}

void	is_eating(t_philo *philo)
{
	t_common	*common;

	common = philo->common;
	mutex_print(philo, "is eating");
	while (get_data_mutex(&common->stop) == 0)
	{
		if (time_since_launch(common) >= philo->dead_line)
		{
			set_data_mutex(&common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		if (time_since_launch(common) >= philo->end_of_meal)
		{
			philo->nb_meal++;
			count_philo_satiatates(philo);
			re_init_values(philo);
			philo->end_of_sleeping = time_since_launch(common)
				+ philo->common->time_to_sleep;
			break ;
		}
		usleep(400);
	}
}
