/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:29:33 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/03 12:12:27 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

int	init_mutex_common(t_common *common)
{
	if (pthread_mutex_init(&common->count_start.mutex, NULL) != 0)
		return(0);
	if (pthread_mutex_init(&common->stop.mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&common->begin_simulation.mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&common->all_philo_satiated.mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&common->printf_mutex, NULL) != 0)
		return (0);
	set_data_mutex(&common->all_philo_satiated, 0);
	set_data_mutex(&common->count_start, 0);
	set_data_mutex(&common->stop, 0);
	set_data_mutex(&common->begin_simulation, 0);
	return (1);
}

size_t	get_data_mutex(t_shared *data_shared)
{
	size_t data;

	pthread_mutex_lock(&data_shared->mutex);
	data = data_shared->data;
	pthread_mutex_unlock(&data_shared->mutex);
	return (data);
}

void	set_data_mutex(t_shared *data_shared, size_t data)
{
	pthread_mutex_lock(&data_shared->mutex);
	data_shared->data = data;
	pthread_mutex_unlock(&data_shared->mutex);
}
