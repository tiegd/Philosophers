/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/06 12:07:04 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_common	common;
	t_fork		*tab_fork;
	t_philo		*tab_philo;

	if (!check_args(ac, av))
		return (1);
	common = init_common(ac, av);
	if (is_zero(&common))
		return (1);
	init_mutex_common(&common);
	tab_fork = init_forks(&common);
	if (!tab_fork)
		return (1);
	if (common.err_mut != 0)
		return (1);
	tab_philo = init_philos(&common, tab_fork);
	if (!tab_philo)
		return (1);
	if (!launch_threads(&common))
	{
		free_all(&common, tab_philo, tab_fork);
		return (1);
	}
	free_all(&common, tab_philo, tab_fork);
	return (0);
}
