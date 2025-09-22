/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:17:26 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 10:42:15 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int check_nb_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	return (1);
}

int	check_nb_philo(char *s)
{
	if (ft_strcmp(s, "1\0") == 0)
	{
		printf("Only one philo can't eat\n");
		return (0);
	}
	if (ft_strcmp(s, "0\0") == 0)
	{
		printf("There is no philosopher\n");
		return (0);
	}
	return (1);
}

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

int	parsing(int ac, char **av)
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
