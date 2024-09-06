/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:34:49 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAGENTA "\x1b[95m"
# define RED "\x1b[91m"
# define ORANGE_FLUO "\033[38;5;208m"
# define RESET "\x1b[0m"

typedef struct s_data
{
	long			ph_nb;
	long			t_die;
	long			t_eating;
	long			t_sleep;
	long			meal;
	struct timeval	start_time;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*meal_sem;
	sem_t			*nb_meal;
	sem_t			*dead_flag;
	struct s_ph		*ph;

}					t_data;

typedef struct s_ph
{
	int				id;
	pid_t			pid;
	long			t_die;
	int				meal_flag;
	int				*dead_flag;
	struct timeval	last_meal;
	t_data			*data;
	pthread_t		supervizor;
}					t_ph;

// parsing
int					ft_atol(const char *s);
int					ft_strcmp(char *str, char *s);
int					ft_error(int code);

// init
int					ft_data_init(char **av, t_data *data);
void				ft_init_philo(t_ph *ph, t_data *data, char **av);
void				ft_sem_init(t_data *data);

// utils
int					ft_is_digit(char c);
int					ft_check_digit(char **av);
int					ft_valid_input(t_data *data);
long				ft_gettime_from(struct timeval start);
void				ft_write_status(t_ph *ph, char *s);
void				ft_usleep(long time, t_ph *ph);
void				ft_destroy(t_data *data);
int					ft_strcmp(char *str, char *s);
int					ft_check_death(t_ph *ph);
int					ft_check_meal(t_ph *ph);

// routine
void				ft_routine(t_ph *ph);
void				ft_manage_threads(t_ph *ph, t_data *data);
void				ft_eat(t_ph *ph);
void				ft_sleep_think(t_ph *ph);
void				*ft_supervise(void *arg);
void				ft_philo_solo(t_ph *ph);

#endif