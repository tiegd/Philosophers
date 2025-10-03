/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/03 11:31:55 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


int main(int ac, char **av)
{
	if (!parsing(ac, av))
		return (1);
	return (0);
}
