/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/14 18:09:56 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_common 	common;
	t_fork		*tab_fork;

	if (ac >= 5 && ac <= 6)
	{
		if (ft_strcmp(av[1], "0\0") == 0 || ft_strcmp(av[1], "1\0") == 0)
		{
			printf("philo 1 died\n");
			return (0);
		}
		common = init_common(ac, av);
		tab_fork = init_forks(common);
		// fill_args(ac, av, common);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	free_forks(tab_fork);
	return (0);
}
