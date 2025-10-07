/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:55 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 13:28:48 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_common	init_common(int ac, char **av)
{
	t_common	common;

	common.nb_philo = ft_atoi(av[1]);
	common.time_to_die = ft_atoi(av[2]);
	common.time_to_eat = ft_atoi(av[3]);
	common.time_to_sleep = ft_atoi(av[4]);
	common.err_mut = 0;
	common.nb_mutex = 0;
	common.stop.data = 0;
	common.all_philo_satiated.data = 0;
	common.start.data = 0;
	common.stop.data = 0;
	common.begin_simulation.data = 0;
	if (ac == 6)
		common.nb_must_eat = ft_atoi(av[5]);
	else
		common.nb_must_eat = -1;
	return (common);
}

t_fork	*init_forks(t_common *common)
{
	size_t	i;
	t_fork	*tab_fork;

	i = 1;
	tab_fork = malloc(common->nb_philo * sizeof(t_fork));
	if (!tab_fork)
		return (NULL);
	while (i <= common->nb_philo)
	{
		tab_fork[i - 1].id_fork = i;
		tab_fork[i - 1].avalable.data = 1;
		i++;
	}
	common->head_tab_fork = tab_fork;
	if (!init_mutex_fork(common))
	{
		free(tab_fork);
		return (NULL);
	}
	return (tab_fork);
}

static void	end_init_philo(t_philo *tab_philo, size_t i)
{
	tab_philo[i].philo_id = i + 1;
	tab_philo[i].nb_meal = 0;
	tab_philo[i].fork_left_av = 0;
	tab_philo[i].fork_right_av = 0;
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
		end_init_philo(tab_philo, i);
		i++;
	}
	common->head_tab_philo = tab_philo;
	return (tab_philo);
}
