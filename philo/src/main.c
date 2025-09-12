/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:50 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/12 09:50:52 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

int main(int ac, char **av)
{
	(void)av;
	if (ac < 4)
	{
		printf("Too few argumens\n");
		return (1);
	}
	if (ac == 4)
	{
		printf("No option of numeber_of_time_each_philosopher_must_eat\n");
	}
	if (ac == 5)
	{
		printf("Option of numeber_of_time_each_philosopher_must_eat\n");
	}
	if (ac > 5)
	{
		printf("To many arguments\n");
		return (1);
	}
	return (0);
}
