/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/16 15:51:07 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_fork
{
	pthread_mutex_t	fork_mutex;
	int				id_fork;
	int				avalable;
}					t_fork;

typedef struct	s_common
{
	pthread_mutex_t	common_mutex;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				died;
}					t_common;

typedef struct	s_philo
{
	pthread_t		tid;
	t_common	*common;
	t_fork		*left_fork; //nb_philo + 1
	t_fork		*right_fork; //nb_philo
	int			philo_id;
	bool		is_sleeping;
	bool		is_eating;
	bool		is_thinking;
	bool		is_died;
}				t_philo;

int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *nptr);
t_common	init_common(int ac, char **av);
t_fork		*init_forks(t_common common);
t_philo		*init_philos(t_common common, t_fork *tab_fork);
void		print_tab_fork(t_fork *tab_fork, t_common common);
void		print_tab_philo(t_philo *tab_philo, t_common common);

#endif
