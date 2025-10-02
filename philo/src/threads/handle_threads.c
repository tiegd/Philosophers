/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:59 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/02 15:16:36 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

void	wait_launch(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->count_start.mutex);
	philo->common->count_start.data++;
	pthread_mutex_unlock(&philo->common->count_start.mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->common->count_start.mutex);
		if (philo->common->count_start.data == philo->common->nb_philo)
		{
			if (get_data_mutex(&philo->common->begin_simulation) == 0)
			{
				// gettimeofday(&philo->common->tv, NULL);
				// set_data_mutex(&philo->common->begin_simulation, philo->common->tv.tv_usec);
				set_data_mutex(&philo->common->begin_simulation, get_curent_time(philo->common));
			}
			pthread_mutex_unlock(&philo->common->count_start.mutex);
			break;
		}
		pthread_mutex_unlock(&philo->common->count_start.mutex);
		usleep(400);
	}
}

void	*routine(void *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)data;
	wait_launch(philo);
	// philo->last_meal = philo->common->tv.tv_usec - philo->common->begin_simulation.data;
	// philo->dead_line = philo->common->begin_simulation.data + philo->common->time_to_die;
	philo->last_meal = get_curent_time(philo->common) - philo->common->begin_simulation.data;
	printf(BLUE"philo->last_meal = %d\n"RESET, philo->last_meal);
	philo->dead_line = philo->common->begin_simulation.data + philo->common->time_to_die;
	if (philo->philo_id % 2 != 0)
	{
		printf(RED"philo %d is waiting\n"RESET, philo->philo_id);
		usleep(philo->common->time_to_eat / 2);
	}
	philo_action(philo);
	if (get_data_mutex(&philo->common->stop) == 1)
		return (NULL);
	return (NULL);
}

int	launch_threads(t_common *common)
{
	int		i;
	int		nb_philo_cp;
	t_philo	*tab_philo;

	i = 0;
	tab_philo = common->head_tab_philo;
	nb_philo_cp = common->nb_philo;
	while (i <= nb_philo_cp - 1)
	{
		if (pthread_create(&tab_philo[i].tid, NULL, &routine, &tab_philo[i]) != 0)
		{
			free_all(tab_philo, common->head_tab_fork);
			return (0);
		}
		i++;
	}
	return (1);
}

void	wait_threads_end(t_philo *tab_philo)
{
	int	i;
	int	nb_philo_cp;
	
	i = 0;
	nb_philo_cp = tab_philo->common->nb_philo;
	while (i <= nb_philo_cp - 1)
	{
		pthread_join(tab_philo[i].tid, NULL);
		i++;
	}
}
