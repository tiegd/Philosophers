/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:04:45 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/04 12:30:43 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	free_all(t_philo *tab_philo, t_fork *tab_fork)
{
	free(tab_fork);
	free(tab_philo);
}

void	destroy_all_mutex(t_common *common)
{
	size_t	i;

	i = 0;
	while (i < common->nb_philo)
	{
		pthread_mutex_destroy(&common->head_tab_fork[i].avalable.mutex);
		i++;
	}
	pthread_mutex_destroy(&common->stop.mutex);
	// pthread_mutex_destroy(&common->count_start.mutex);
	pthread_mutex_destroy(&common->start.mutex);
	pthread_mutex_destroy(&common->begin_simulation.mutex);
	pthread_mutex_destroy(&common->all_philo_satiated.mutex);
	pthread_mutex_destroy(&common->printf_mutex);
}
