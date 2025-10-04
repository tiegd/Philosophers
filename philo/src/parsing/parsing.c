/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:17:26 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/04 14:01:35 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <limits.h>

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

int	is_overflow(const char *nptr)
{
	int	count;

	count = 0;
	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
	{
		count = (count * 10) + (*nptr - '0');
		if ((unsigned long long) count > INT_MAX)
		{
			printf("One or more argument is too big\n");
			return (1);
		}
		nptr++;
	}
	return (0);
}

static int	check_args(int ac, char **av)
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
		if (is_overflow(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	t_common	common;
	t_fork		*tab_fork;
	t_philo		*tab_philo;

	if (!check_args(ac, av))
		return (0);
	common = init_common(ac, av);
	if (!init_mutex_common(&common))
		return (0);
	tab_fork = init_forks(&common);
	tab_philo = init_philos(&common, tab_fork);
	if (!launch_threads(&common))
	{
		free_all(tab_philo, tab_fork);
		return (0);
	}
	wait_threads_end(tab_philo);
	destroy_all_mutex(&common);
	free_all(tab_philo, tab_fork);
	return (1);
}
