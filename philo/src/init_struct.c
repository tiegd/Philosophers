/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:18:55 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/14 18:06:34 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

t_common	init_common(int ac, char **av)
{
	t_common	common;
	
	common.nb_philo = ft_atoi(av[1]);
	common.time_to_die = ft_atoi(av[2]);
	common.time_to_eat = ft_atoi(av[3]);
	common.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		common.nb_must_eat = ft_atoi(av[5]);
	else
		common.nb_must_eat = -1;
	return (common);
}

t_fork	*init_forks(t_common common)
{
	int		i;
	int		j;
    t_fork	*tab_fork;

	i = 1;
	j = 0;
	tab_fork = malloc((common.nb_philo + 1) * sizeof(t_fork));
	while (i <= common.nb_philo)
	{
		pthread_mutex_init(&tab_fork[j].fork, NULL);
		tab_fork[j].id_fork = i;
		tab_fork[j].avalable = 0;
		i++;
		j++;
	}
	return (tab_fork);
}
