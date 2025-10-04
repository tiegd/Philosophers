/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:55 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/04 17:10:08 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_common	init_common(int ac, char **av)
{
	t_common	common;

	common.nb_philo = ft_atoi(av[1]);
	common.time_to_die = (size_t)ft_atoi(av[2]);
	common.time_to_eat = (size_t)ft_atoi(av[3]);
	common.time_to_sleep = (size_t)ft_atoi(av[4]);
	common.stop.data = 0;
	if (ac == 6)
		common.nb_must_eat = (size_t)ft_atoi(av[5]);
	else
		common.nb_must_eat = -1;
	return (common);
}

t_fork	*init_forks(t_common *common)
{
	int		j;
	size_t	i;
	t_fork	*tab_fork;

	i = 1;
	j = 0;
	tab_fork = malloc(common->nb_philo * sizeof(t_fork));
	if (!tab_fork)
		return (NULL);
	while (i <= common->nb_philo)
	{
		pthread_mutex_init(&tab_fork[j].avalable.mutex, NULL);//verif
		pthread_mutex_init(&tab_fork[j].locked_by.mutex, NULL);//verif
		tab_fork[j].id_fork = i;
		tab_fork[j].avalable.data = 1;
		tab_fork[j].locked_by.data = 0;
		i++;
		j++;
	}
	common->head_tab_fork = tab_fork;
	return (tab_fork);
}

t_philo	*init_philos(t_common *common, t_fork *tab_fork)
{
	t_philo	*tab_philo;
	size_t	i;

	i = 0;
	tab_philo = malloc(common->nb_philo * sizeof(t_philo));
	if (!tab_philo)
	{
		free(tab_fork);
		return (NULL);
	}
	while (i <= common->nb_philo - 1)
	{
		tab_philo[i].common = common;
		tab_philo[i].left_fork = &tab_fork[i];
		if (i != 0)
			tab_philo[i].right_fork = &tab_fork[i - 1];
		if (i == 0)
			tab_philo[i].right_fork = &tab_fork[common->nb_philo - 1];
		tab_philo[i].philo_id = i + 1;
		tab_philo[i].nb_meal = 0;
		i++;
	}
	common->head_tab_philo = tab_philo;
	return (tab_philo);
}
