/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 13:09:20 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	wait_launch(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->common_mutex);
	philo->common->count_start++;
	pthread_mutex_unlock(&philo->common->common_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->common->common_mutex);
		if (philo->common->count_start == philo->common->nb_philo)
		{
			pthread_mutex_unlock(&philo->common->common_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->common->common_mutex);
		usleep(100);
	}
}
void	*routine(void *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = (t_philo *)data;
	wait_launch(philo);
	while (i++ < 5)
		display_move(philo);
	if (philo->common->died == 1)
		return (NULL);
	return (NULL);
}

int main(int ac, char **av)
{
	t_common 	common;
	t_fork		*tab_fork;
	t_philo		*tab_philo;
	int			i;

	i = 0;
	if (!parsing(ac, av))
		return (0);
	common = init_common(ac, av);
	tab_fork = init_forks(&common);
	tab_philo = init_philos(&common, tab_fork);
	// print_tab_philo(tab_philo, common);
	while (i <= common.nb_philo - 1)
	{
		pthread_create(&tab_philo[i].tid, NULL, &routine, &tab_philo[i]);
		i++;
	}
	i = 0;
	while (i <= common.nb_philo - 1)
	{
		pthread_join(tab_philo[i].tid, NULL);
		i++;
	}
	free(tab_fork);
	free(tab_philo);
	return (0);
}
