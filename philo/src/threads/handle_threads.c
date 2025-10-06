/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:59 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/06 19:10:09 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	my_usleep(t_philo *philo, size_t time)
{
	size_t	end;

	end = get_curent_time(philo->common) + time;
	while (get_curent_time(philo->common) < end)
	{
		if (get_data_mutex(&philo->common->stop) == 1)
			break ;
		usleep(500);
	}
}

static void	*routine(void *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->common->start.mutex);
	pthread_mutex_unlock(&philo->common->start.mutex);
	if (get_data_mutex(&philo->common->stop) == 1)
		return (NULL);
	philo->last_meal = time_since_launch(philo->common);
	philo->dead_line = philo->last_meal + philo->common->time_to_die;
	mutex_print(philo, "is thinking");
	if (philo->philo_id % 2 != 0)
		my_usleep(philo, (philo->common->time_to_eat / 2));
	philo_action(philo, 0);
	if (get_data_mutex(&philo->common->stop) == 1)
		return (NULL);
	return (NULL);
}

// static void	monitor_routine()
// {
	
// }

int	launch_threads(t_common *common)
{
	int			i;
	int			nb_philo_cp;
	// pthread_t	monitor_tid;
	t_philo		*tab_philo;

	i = 0;
	tab_philo = common->head_tab_philo;
	nb_philo_cp = common->nb_philo;
	pthread_mutex_lock(&common->start.mutex);
	while (i <= nb_philo_cp - 1)
	{
		if (pthread_create(&tab_philo[i].tid, NULL, &routine,
				&tab_philo[i]) != 0)
		{
			tab_philo->common->nb_philo = i;
			set_data_mutex(&common->stop, 1);
			pthread_mutex_unlock(&common->start.mutex);
			return (0);
		}
		i++;
	}
	// if (pthread_create(&monitor_tid, NULL, &monitor_routine, &common))
	set_data_mutex(&common->begin_simulation, get_curent_time(common));
	pthread_mutex_unlock(&common->start.mutex);
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
