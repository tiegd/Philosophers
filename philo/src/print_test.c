/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:38:59 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/16 12:28:36 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_tab_fork(t_fork *tab_fork, t_common common)
{
	int	i;

	i = 0;
	while (i <= common.nb_philo - 1)
	{
		printf("tab_fork[%d].id_fork = %d\ntab_fork[%d].avalable = %d\n", i, tab_fork[i].id_fork, i, tab_fork[i].avalable);
		i++;
	}
}
