/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 09:23:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	mutex_print(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->common->printf_mutex);
	printf("%zu %zu %s\n", time_since_launch(philo->common),
		philo->philo_id, s);
	pthread_mutex_unlock(&philo->common->printf_mutex);
}

void	philo_action(t_philo *philo, int init)
{
	t_common	*common;

	common = philo->common;
	while (get_data_mutex(&common->stop) == 0)
	{
		if (get_data_mutex(&common->stop) == 0)
			is_thinking(philo, init);
		if (get_data_mutex(&common->stop) == 0)
			is_eating(philo);
		if (get_data_mutex(&common->stop) == 0)
			is_sleeping(philo);
		if (init == 0)
			init = 1;
		usleep(400);
	}
}
