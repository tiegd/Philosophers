/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:42:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/03 14:02:47 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	philo_action(t_philo *philo)
{
	while (get_data_mutex(&philo->common->stop) == 0)
	{
		if (get_data_mutex(&philo->common->stop) == 0)
			is_thinking(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_eating(philo);
		if (get_data_mutex(&philo->common->stop) == 0)
			is_sleeping(philo);
		usleep(500);
		// printf("philo[%zu]; stop = %zu\n", philo->philo_id, philo->common->stop.data);
	}
}
