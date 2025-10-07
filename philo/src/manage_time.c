/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:50:14 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 13:15:24 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_curent_time_common(t_common *common)
{
	size_t	time_mili;
	size_t	sec;
	size_t	micro;

	gettimeofday(&common->tv, NULL);
	sec = common->tv.tv_sec * 1000;
	micro = common->tv.tv_usec / 1000;
	time_mili = sec + micro;
	return (time_mili);
}

size_t	get_curent_time_philo(t_philo *philo)
{
	size_t	time_mili;
	size_t	sec;
	size_t	micro;

	gettimeofday(&philo->tv, NULL);
	sec = philo->tv.tv_sec * 1000;
	micro = philo->tv.tv_usec / 1000;
	time_mili = sec + micro;
	return (time_mili);
}

size_t	time_since_launch(t_philo *philo)
{
	size_t	curent_time;
	size_t	time_since_launch;

	curent_time = get_curent_time_philo(philo);
	time_since_launch = curent_time - philo->common->begin_simulation.data;
	return (time_since_launch);
}
