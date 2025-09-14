/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/14 18:09:41 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int				id_fork;
	int				avalable;
}					t_fork;

typedef struct	s_common
{
	// t_philo			**tab_philo;
	// t_fork			**tab_fork;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
}					t_common;

typedef struct	s_philo
{
	int			philo_id;
	int			is_sleeping;
	int			is_eating;
	int			is_thinking;
	int			died;
	t_fork		*left_fork; //nb_philo - 1
	t_fork		*right_fork; //nb_philo + 1
	t_common	*common;
}				t_philo;

int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *nptr);
t_common	init_common(int ac, char **av);
t_fork		*init_forks(t_common common);
void		free_forks(t_fork *fork);

#endif
