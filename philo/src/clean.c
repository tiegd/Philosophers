/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:04:45 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/26 10:55:06 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	free_all(t_philo *tab_philo, t_fork *tab_fork)
{
	free(tab_fork);
	free(tab_philo);
}
