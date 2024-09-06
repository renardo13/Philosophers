/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:11 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 14:16:15 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_solo(t_ph *ph)
{
	ft_take_right_fork(ph);
	pthread_mutex_unlock(&ph->r_fork);
	ft_usleep(ph->data->t_die, ph);
	pthread_mutex_lock(&ph->data->mutex);
	printf(RED "%ld %d died 🏴💀\n" RESET, ft_gettime_from(ph->data->start_time),
		ph->id);
	pthread_mutex_unlock(&ph->data->mutex);
}

int	ft_enough_meal(t_ph *ph)
{
	long	total_meal;
	long	ph_nb;
	long	meal;
	int		i;

	i = 0;
	ph_nb = ft_getter(&ph->data->ph_nb, &ph->data->mutex);
	while (i < ph_nb)
	{
		total_meal = ft_getter(&ph[i].data->general_meal_counter,
				&ph->data->mutex);
		meal = ft_getter(&ph[i].data->meal, &ph[i].data->mutex);
		if (total_meal == meal * ph_nb)
		{
			ft_usleep(ph->data->t_eating, ph);
			pthread_mutex_lock(&ph->data->mutex);
			printf(ORANGE_FLUO "Everyone have finished their meal 🍽️\n" RESET);
			pthread_mutex_unlock(&ph->data->mutex);
			return (1);
		}
		i++;
	}
	return (0);
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

void	ft_write_status(t_ph *ph, char *s)
{
	if (ft_getter(&ph->data->dead_flag, &ph->data->mutex))
		return ;
	if (ft_getter(&ph->meal_flag, &ph->ph_mutex) && ph->data->ph_nb > 1)
	{
		if (ft_getter(&ph->data->general_meal_counter,
				&ph->data->mutex) >= ft_getter(&ph->data->meal,
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
