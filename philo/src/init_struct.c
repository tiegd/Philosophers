/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:55 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 11:09:28 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

t_common	init_common(int ac, char **av)
{
	t_common	common;

	pthread_mutex_init(&common.common_mutex, NULL); //for lock common.died
	common.nb_philo = ft_atoi(av[1]);
	common.time_to_die = ft_atoi(av[2]);
	common.time_to_eat = ft_atoi(av[3]);
	common.time_to_sleep = ft_atoi(av[4]);
	common.died = -1;
	common.count_start = 0;
	if (ac == 6)
		common.nb_must_eat = ft_atoi(av[5]);
	else
		common.nb_must_eat = -1;
	return (common);
}

t_fork	*init_forks(t_common *common)
{
	int		i;
	int		j;
    t_fork	*tab_fork;

	i = 1;
	j = 0;
	tab_fork = malloc(common->nb_philo * sizeof(t_fork));
	if (!tab_fork)
		return (NULL);
	while (i <= common->nb_philo)
	{
		pthread_mutex_init(&tab_fork[j].fork_mutex, NULL);
		tab_fork[j].id_fork = i;
		tab_fork[j].avalable = 0;
		i++;
		j++;
	}
	return (tab_fork);
}

t_philo	*init_philos(t_common *common, t_fork *tab_fork)
{
	t_philo	*tab_philo;
	int		i;
	// int		j;

	i = 0;
	// j = 1;
	tab_philo = malloc(common->nb_philo * sizeof(t_philo));
	// if (!tab_philo)
	// 	return (NULL);
	while (i <= common->nb_philo - 1)
	{
		tab_philo[i].common = common;
		tab_philo[i].left_fork = &tab_fork[i];
		if (i != 0)
			tab_philo[i].right_fork = &tab_fork[i - 1];
		if (i == 0)
			tab_philo[i].right_fork = &tab_fork[common->nb_philo - 1];
		tab_philo[i].philo_id = i + 1;
		tab_philo[i].is_sleeping = false;
		tab_philo[i].is_died = 0;
		tab_philo[i].is_thinking = false;
		tab_philo[i].is_died = false;
		i++;
	}
	return (tab_philo);
}
