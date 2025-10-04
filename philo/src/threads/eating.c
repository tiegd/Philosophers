/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:25:34 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/04 14:28:00 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	can_eat(t_philo *philo)
{
	if (philo->left_fork->id_fork != philo->right_fork->id_fork)
	{
		if (get_data_mutex(&philo->left_fork->locked_by) == philo->philo_id
			&& get_data_mutex(&philo->right_fork->locked_by)
			== philo->philo_id)
		{
			philo->last_meal = time_since_launch(philo->common);
			philo->end_of_meal = philo->last_meal
				+ philo->common->time_to_eat;
			return (1);
		}
	}
	return (0);
}

static void	re_init_values(t_philo *philo)
{
	set_data_mutex(&philo->left_fork->avalable, 1);
	set_data_mutex(&philo->right_fork->avalable, 1);
	set_data_mutex(&philo->left_fork->locked_by, 0);
	set_data_mutex(&philo->right_fork->locked_by, 0);
}

static void	count_philo_satiatates(t_philo *philo)
{
	if (philo->common->nb_must_eat >= 0)
	{
		if (philo->nb_meal == philo->common->nb_must_eat)
			set_data_mutex(&philo->common->all_philo_satiated,
				philo->common->all_philo_satiated.data + 1);
		if (get_data_mutex(&philo->common->all_philo_satiated)
			== philo->common->nb_philo)
			set_data_mutex(&philo->common->stop, 1);
	}
}

void	is_eating(t_philo *philo)
{
	mutex_print(philo, "is eating");
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (time_since_launch(philo->common) >= philo->dead_line)
		{
			set_data_mutex(&philo->common->stop, 1);
			mutex_print(philo, "died");
			break ;
		}
		if (time_since_launch(philo->common) >= philo->end_of_meal)
		{
			philo->nb_meal++;
			count_philo_satiatates(philo);
			re_init_values(philo);
			philo->end_of_sleeping = time_since_launch(philo->common)
				+ philo->common->time_to_sleep;
			break ;
		}
		usleep(500);
	}
}
