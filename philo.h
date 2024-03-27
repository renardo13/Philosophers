/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 15:51:31 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAGENTA "\x1b[95m"
# define RED "\x1b[91m"
# define ORANGE_FLUO "\033[38;5;208m"
# define RESET "\x1b[0m"

// the data struct is shared ressources
// philo struct is proper to any philo

typedef struct s_data
{
	long			ph_nb;
	long			t_die;
	long			t_eating;
	long			t_sleep;
	long			t_think;
	long			t_eat;
	long			general_meal_counter;
	long			all_ready;
	long			dead_flag;
	struct timeval	start_time;
	pthread_mutex_t	mutex;
}					t_data;
// set at 1 if they have to eat a particular number of meal
typedef struct s_ph
{
	int				id;
	long			meal_flag;
	struct timeval	last_meal;
	long			meal_counter;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	ph_mutex;
	pthread_t		ph_thread_id;
	t_data			*data;
}					t_ph;

// flag set at 1 to know if a philo already get a right or a left fork
// like this I can transfert data from the data struct when I initialize threadu

// init

int					ft_data_init(char **av, t_data *data);
void				ft_init_philo(t_ph *ph, t_data *data, char **av);

// setter

void				ft_last_meal_setter(struct timeval *val,
						struct timeval *last_meal, pthread_mutex_t *mutex);
void				ft_setter(long val, long *flag, pthread_mutex_t *mutex);
struct timeval		ft_last_meal_getter(struct timeval *last_meal,
						pthread_mutex_t *mutex);
long				ft_getter(long *val, pthread_mutex_t *mutex);

// utils

long				ft_gettime_from(struct timeval start);
void				ft_write_status(t_ph *ph, char *s);
void				ft_print_die(t_ph *ph);
void				ft_kill_phil(t_data *data, t_ph *ph);
void				ft_meal_counter(long *flag, pthread_mutex_t *mutex);

// routine

void				ft_take_left_fork(t_ph *ph);
void				ft_take_right_fork(t_ph *ph);
void				ft_eat(t_ph *ph);
void				ft_sleep_think(t_ph *ph);
void				ft_supervise(t_ph *ph, int ph_nb);
void				ft_enough_meal(t_ph *ph);

// parsing
int					ft_atoi(const char *s);
char				*ft_itoa(int n);
int					ft_strcmp(char *str, char *s);
int					ft_error(int code);

#endif