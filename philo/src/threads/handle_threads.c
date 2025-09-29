/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:59 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/29 13:44:12 by gaducurt         ###   ########.fr       */
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
		// printf(GREEN"begin_simulation = %d\n"RESET, philo->common->begin_simulation.data);
		pthread_mutex_lock(&philo->common->count_start.mutex);
		if (philo->common->count_start.data == philo->common->nb_philo)
		{
			if (get_data_mutex(&philo->common->begin_simulation) == 0)
				set_data_mutex(&philo->common->begin_simulation, philo->common->tv.tv_usec);
			pthread_mutex_unlock(&philo->common->count_start.mutex);
			break;
		}
		pthread_mutex_unlock(&philo->common->count_start.mutex);
		usleep(500);
	}
}

void	*routine(void *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)data;
	wait_launch(philo);
	printf(RED"%d\n"RESET, philo->common->begin_simulation.data);
	philo->last_meal = philo->common->begin_simulation.data;
	// printf("%d\n", philo->last_meal);
	display_action(philo);
	if (philo->common->stop.data == 1)
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
