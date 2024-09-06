/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:11 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 15:54:48 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_solo(t_ph *ph)
{
	if (!ph->data->meal)
	{
		pthread_join(ph->supervizor, NULL);
		ft_destroy(ph->data);
		exit(1);
	}
	sem_wait(ph->data->forks);
	ft_write_status(ph, "FORK");
	pthread_join(ph->supervizor, NULL);
	ft_destroy(ph->data);
	exit(10);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_write_status(t_ph *ph, char *s)
{
	long	ms;

	ms = ft_gettime_from(ph->data->start_time);
	sem_wait(ph->data->print_sem);
	if (!ft_strcmp("FORK", s))
		printf("%ld %d has taken a fork\n", ms, ph->id);
	else if (!ft_strcmp("EAT", s))
		printf("%ld %d is eating\n", ms, ph->id);
	else if (!ft_strcmp("SLEEP", s))
		printf("%ld %d is sleeping\n", ms, ph->id);
	else if (!ft_strcmp("THINK", s))
		printf("%ld %d is thinking\n", ms, ph->id);
	sem_post(ph->data->print_sem);
}

void	ft_usleep(long time, t_ph *ph)
{
	struct timeval	start;
	long			t_start;
	long			t_curr;

	gettimeofday(&start, NULL);
	t_start = 0;
	t_curr = 0;
	while (t_curr < time)
	{
		if (ft_check_death(ph))
		{
			pthread_join(ph->supervizor, NULL);
			ft_destroy(ph->data);
			exit(10);
		}
		t_curr = ft_gettime_from(start);
		usleep(time / 10);
	}
}

long	ft_gettime_from(struct timeval start)
{
	struct timeval	now;
	long			time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) - (start.tv_sec * 1000);
	time += (now.tv_usec / 1000) - (start.tv_usec / 1000);
	return (time);
}
