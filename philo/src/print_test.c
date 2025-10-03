/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:38:59 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/03 12:54:35 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_tab_fork(t_fork *tab_fork, t_common common)
{
	size_t	i;

	i = 0;
	while (i <= common.nb_philo - 1)
	{
		printf("tab_fork[%zu].id_fork = %d\ntab_fork[%zu].avalable = %zu\n", i, tab_fork[i].id_fork, i, tab_fork[i].avalable.data);
		i++;
	}
}

void	print_tab_philo(t_philo *tab_philo, t_common common)
{
	size_t	i;

	i = 0;
	while (i <= common.nb_philo - 1)
	{
		printf("i = %zu\n", i);
		printf("tab_philo[%zu].philo_id = %zu\n", i, tab_philo[i].philo_id);
		printf("common.nb_philo = %zu\n", common.nb_philo);
		printf("left_fork = %d\n", tab_philo[i].left_fork->id_fork);
		printf("right_fork = %d\n", tab_philo[i].right_fork->id_fork);
		i++;
	}
}

void	print_tab_in_common(t_common *common)
{
	
	size_t	i;

	i = 0;
	while (i <= common->nb_philo - 1)
	{
		printf("i = %zu\n", i);
		printf("%zu\n", common->head_tab_philo[i].philo_id);
		i++;
	}
}
