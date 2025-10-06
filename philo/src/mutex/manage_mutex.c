/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:29:33 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/06 11:02:04 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	init_mutex_common(t_common *common)
{
	if (common->err_mut == 0 && pthread_mutex_init(&common->start.mutex, NULL) != 0)
		destroy_fail_mutex(common);
	common->nb_mutex++;
	if (common->err_mut == 0 && pthread_mutex_init(&common->stop.mutex, NULL) != 0)
		destroy_fail_mutex(common);
	common->nb_mutex++;
	if (common->err_mut == 0 && pthread_mutex_init(&common->begin_simulation.mutex, NULL) != 0)
		destroy_fail_mutex(common);
	common->nb_mutex++;
	if (common->err_mut == 0 && pthread_mutex_init(&common->all_philo_satiated.mutex, NULL) != 0)
		destroy_fail_mutex(common);
	common->nb_mutex++;
	if (common->err_mut == 0 && pthread_mutex_init(&common->printf_mutex, NULL) != 0)
		destroy_fail_mutex(common);
	common->nb_mutex++;
}

size_t	get_data_mutex(t_shared *data_shared)
{
	size_t	data;

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
