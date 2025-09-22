/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/09/22 16:24:13 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct	s_fork
{
	pthread_mutex_t	fork_mutex;
	int				id_fork;
	int				avalable;
}					t_fork;

typedef struct	s_common
{
	pthread_mutex_t	common_mutex;
	struct timeval	tv;
	struct timezone	tz;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				count_start;
	int				begin_simulation;
	int				died;
}					t_common;

typedef struct	s_philo
{
	pthread_t		tid;
	t_common	*common;
	t_fork		*left_fork; //nb_philo + 1
	t_fork		*right_fork; //nb_philo
	int			philo_id;
	// int			is_died;
	int			last_meal;
	int			end_of_eating;
	int			end_of_sleeping;
	int			end_of_life;
	// bool		is_thinking;
	// bool		is_sleeping;
	// bool		is_eating;
}				t_philo;


/*-----------INIT-----------*/

t_common	init_common(int ac, char **av);
t_fork		*init_forks(t_common *common);
t_philo		*init_philos(t_common *common, t_fork *tab_fork);

/*-----------PARSING-----------*/

int			parsing(int ac, char **av);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *nptr);

/*-----------PRINT_TEST-----------*/

void		print_tab_fork(t_fork *tab_fork, t_common common);
void		print_tab_philo(t_philo *tab_philo, t_common common);

/*-----------UTILS-----------*/

void		display_philo(t_philo *philo);
void		display_move(t_philo *philo);

#endif
