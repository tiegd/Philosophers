/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:17:26 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/07 10:59:14 by gaducurt         ###   ########.fr       */
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
			ft_putstr_fd("Input is not valid\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

// int	is_overflow(const char *nptr)
// {
// 	int	count;

// 	count = 0;
// 	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
// 	{
// 		count = (count * 10) + (*nptr - '0');
// 		if ((unsigned long long) count > INT_MAX)
// 		{
// 			ft_putstr_fd("One or more argument is too big\n", 2);
// 			return (1);
// 		}
// 		nptr++;
// 	}
// 	return (0);
// }

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (!check_nb_args(ac))
		return (0);
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_putstr_fd("Input is not valid\n", 2);
			return (0);
		}
		if (!is_valid(av[i]))
			return (0);
		if (is_overflow(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_zero_bis(t_common *common)
{
	if (common->time_to_sleep == 0)
	{
		ft_putstr_fd("Input is not valid\n", 2);
		return (1);
	}
	if (common->nb_must_eat == 0)
	{
		ft_putstr_fd("Input is not valid\n", 2);
		return (1);
	}
	return (0);
}

int	is_zero(t_common *common)
{
	if (common->nb_philo == 0)
	{
		ft_putstr_fd("Input is not valid\n", 2);
		return (1);
	}
	if (common->time_to_die == 0)
	{
		ft_putstr_fd("Input is not valid\n", 2);
		return (1);
	}
	if (common->time_to_eat == 0)
	{
		ft_putstr_fd("Input is not valid\n", 2);
		return (1);
	}
	return (0);
}
