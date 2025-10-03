/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:32:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/10/03 13:00:08 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <inttypes.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"

struct t_philo;

typedef struct	s_shared
{
	// uint32_t		data; //on ne dépasse jamais 32 bit 
	size_t			data;
	uint8_t			state;
	pthread_mutex_t	mutex;
}					t_shared;

typedef struct	s_fork
{
	t_shared		avalable;
	int				id_fork;
	t_shared		locked_by;
	// int				locked_by;
	// int				avalable;
}					t_fork;

typedef struct	s_common
{
	t_shared		stop;
	t_shared		count_start;
	t_shared		begin_simulation;
	pthread_mutex_t	printf_mutex;
	struct s_philo	*head_tab_philo;
	t_fork			*head_tab_fork;
	struct timeval	tv;
	// struct timezone	tz;
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			nb_must_eat;
	t_shared		all_philo_satiated;
}					t_common;

typedef struct	s_philo
{
	pthread_t		tid;
	t_common		*common;
	t_fork			*left_fork; //nb_philo + 1
	t_fork			*right_fork; //nb_philo
	size_t			philo_id;
	size_t			nb_meal;
	size_t			last_meal;
	size_t			end_of_meal;
	size_t			end_of_sleeping;
	size_t			dead_line;
}					t_philo;


/*-----------INIT-----------*/

t_common	init_common(int ac, char **av);
t_fork		*init_forks(t_common *common);
t_philo		*init_philos(t_common *common, t_fork *tab_fork);
int			init_mutex_common(t_common *common);

size_t		time_since_launch(t_common *common);
size_t		get_curent_time(t_common *common);

/*-----------PARSING-----------*/

int			parsing(int ac, char **av);
int			check_args(int ac, char **av);
int 		check_nb_args(int ac);
int			check_nb_philo(char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *nptr);

/*-----------PRINT_TEST-----------*/

void		print_tab_fork(t_fork *tab_fork, t_common common);
void		print_tab_philo(t_philo *tab_philo, t_common common);
void		print_tab_in_common(t_common *common);

/*-----------UTILS-----------*/

// void		display_philo(t_philo *philo);
// void		display_action(t_philo *philo);
void		philo_action(t_philo *philo);

/*-----------MANAGE_MUTEX-----------*/

size_t		get_data_mutex(t_shared *data_shared);
void		set_data_mutex(t_shared *data_shared, size_t data);
void		destroy_all_mutex(t_common *common);

/*-----------HANDLE_THREAD-----------*/

int			launch_threads(t_common *common);
void		wait_threads_end(t_philo *tab_philo);
void		wait_launch(t_philo *philo);
void		*routine(void *data);

void		is_thinking(t_philo *philo);
int			check_fork_avalable(t_philo *philo);
void		is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);

/*-----------CLEAN-----------*/

void		free_all(t_philo *tab_philo, t_fork *tab_fork);

#endif
