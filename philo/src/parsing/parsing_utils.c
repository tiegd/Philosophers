/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:23:09 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/02 17:21:17 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (((unsigned char) s1[i] == (unsigned char) s2[i]))
	{
		if ((unsigned char) s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	check_nb_philo(char *s)
{
	// if (ft_strcmp(s, "1\0") == 0)
	// {
	// 	printf("Only one philo can't eat\n");
	// 	return (0);
	// }
	if (ft_strcmp(s, "0\0") == 0)
	{
		printf("There is no philosopher\n");
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	count;
	int	inv;

	count = 0;
	inv = 1;
	while (*nptr == ' ' || ((*nptr >= 9 && *nptr <= 13) && *nptr != 0))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			inv = -inv;
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
	{
		count = (count * 10) + (*nptr - '0');
		if ((unsigned long long) count > (unsigned long long)INT_MAX + 1
			&& inv == -1)
			return (INT_MIN);
		else if ((unsigned long long) count > INT_MAX && inv == 1)
			return (INT_MAX);
		nptr++;
	}
	return (count * inv);
}
