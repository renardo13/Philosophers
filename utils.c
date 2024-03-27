/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:11 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:29 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_enough_meal(t_ph *ph)
{
	long	total_meal;
	long	ph_nb;
	long	t_eat;

	total_meal = ft_getter(&ph->data->general_meal_counter, &ph->data->mutex);
	ph_nb = ft_getter(&ph->data->ph_nb, &ph->data->mutex);
	t_eat = ft_getter(&ph->data->t_eat, &ph->data->mutex);
	if (total_meal == t_eat * ph_nb)
	{
		pthread_mutex_lock(&ph->data->mutex);
		printf(ORANGE_FLUO "Everyone have finished their meal 🍽️\n" RESET);
		pthread_mutex_unlock(&ph->data->mutex);
	}
}

void	ft_kill_phil(t_data *data, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < data->ph_nb)
		pthread_mutex_destroy(&ph[i++].r_fork);
	pthread_mutex_destroy(&data->mutex);
	free(ph);
}

void	ft_print_die(t_ph *ph)
{
	ft_setter(1, &ph->data->dead_flag, &ph->data->mutex);
	usleep(200);
	pthread_mutex_lock(&ph->data->mutex);
	printf(RED "%ld %d died 🏴💀\n" RESET, ft_gettime_from(ph->data->start_time),
		ph->id);
	pthread_mutex_unlock(&ph->data->mutex);
}

void	ft_write_status(t_ph *ph, char *s)
{
	if (ft_getter(&ph->data->dead_flag, &ph->data->mutex) == 1)
		return ;
	if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
	{
		if (ft_getter(&ph->data->general_meal_counter,
				&ph->data->mutex) >= ft_getter(&ph->data->t_eat,
				&ph->data->mutex) * ft_getter(&ph->data->ph_nb,
				&ph->data->mutex))
			return ;
	}
	pthread_mutex_lock(&ph->data->mutex);
	if (!ft_strcmp("FORK", s))
		printf("%ld %d has taken a fork\n",
			ft_gettime_from(ph->data->start_time), ph->id);
	else if (!ft_strcmp("EAT", s))
		printf(MAGENTA "%ld %d is eating\n" RESET,
			ft_gettime_from(ph->data->start_time), ph->id);
	else if (!ft_strcmp("SLEEP", s))
		printf("%ld %d is sleeping\n", ft_gettime_from(ph->data->start_time),
			ph->id);
	else if (!ft_strcmp("THINK", s))
		printf("%ld %d is thinking\n", ft_gettime_from(ph->data->start_time),
			ph->id);
	pthread_mutex_unlock(&ph->data->mutex);
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
