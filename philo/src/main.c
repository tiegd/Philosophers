/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/19 14:45:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->common->common_mutex);
	philo->common->count_start++;
	pthread_mutex_unlock(&philo->common->common_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->common->common_mutex);
		if (philo->common->count_start == philo->common->nb_philo)
		{
			pthread_mutex_unlock(&philo->common->common_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->common->common_mutex);
		usleep(100);
	}
	return (NULL);
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

int main(int ac, char **av)
{
	t_common 	common;
	t_fork		*tab_fork;
	t_philo		*tab_philo;
	int			i;

	i = 0;
	if (ac >= 5 && ac <= 6)
	{
		if (!check_nb_philo(av[1]))
			return (0);
		common = init_common(ac, av);
		tab_fork = init_forks(&common);
		tab_philo = init_philos(&common, tab_fork);
		// fill_args(ac, av, common);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	// free_forks(&tab_fork);
	// print_tab_fork(tab_fork, common);
	print_tab_philo(tab_philo, common);
	while (i <= common.nb_philo - 1)
	{
		pthread_create(&tab_philo[i].tid, NULL, &routine, &tab_philo[i]);
		i++;
	}
	i = 0;
	while (i <= common.nb_philo - 1)
	{
		pthread_join(tab_philo[i].tid, NULL);
		i++;
	}
	// pthread_join(tab_philo[i].tid, NULL);
	free(tab_fork);
	free(tab_philo);
	return (0);
}
