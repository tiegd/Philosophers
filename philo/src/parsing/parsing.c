/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:17:26 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/26 12:19:57 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			printf("Input is not valid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (!check_nb_args(ac))
		return (0);
	if (!check_nb_philo(av[1]))
		return (0);
	while (av[i])
	{
		if (!is_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	t_common 	common;
	t_fork		*tab_fork;
	t_philo		*tab_philo;

	if (!check_args(ac, av))
		return (0);
	common = init_common(ac, av);
	tab_fork = init_forks(&common);
	tab_philo = init_philos(&common, tab_fork);
	if (!launch_threads(&common))
	{
		free_all(tab_philo, tab_fork);
		return (0);
	}
	wait_threads_end(tab_philo);
	free_all(tab_philo, tab_fork);
	return (1);
}
