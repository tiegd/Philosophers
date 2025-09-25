/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:29:33 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/25 15:36:58 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	get_data_mutex(t_shared *data_shared)
{
	uint32_t data;

	pthread_mutex_lock(&data_shared->mutex);
	data = data_shared->data;
	pthread_mutex_unlock(&data_shared->mutex);
	return (data);
}

void	set_data_mutex(t_shared *data_shared, uint32_t data)
{
	pthread_mutex_lock(&data_shared->mutex);
	data_shared->data = data;
	pthread_mutex_unlock(&data_shared->mutex);
}
