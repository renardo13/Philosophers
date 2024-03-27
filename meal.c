/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:03 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:49:44 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_left_fork(t_ph *ph)
{
	pthread_mutex_lock(ph->l_fork);
	ft_write_status(ph, "FORK");
}

void	ft_take_right_fork(t_ph *ph)
{
	pthread_mutex_lock(&ph->r_fork);
	ft_write_status(ph, "FORK");
}

void	ft_sleep_think(t_ph *ph)
{
	ft_write_status(ph, "SLEEP");
	usleep(ph->data->t_sleep * 1000);
	if (ft_getter(&ph->data->dead_flag, &ph->data->mutex))
		return ;
	ft_write_status(ph, "THINK");
	usleep(ph->data->t_think * 1000);
}

void	ft_eat(t_ph *ph)
{
	struct timeval	new_last_meal;

	if (ph->id % 2 == 0)
	{
		ft_take_left_fork(ph);
		ft_take_right_fork(ph);
	}
	else
	{
		ft_take_right_fork(ph);
		ft_take_left_fork(ph);
	}
	gettimeofday(&new_last_meal, NULL);
	ft_write_status(ph, "EAT");
	ft_last_meal_setter(&new_last_meal, &ph->last_meal, &ph->data->mutex);
	if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
	{
		ft_setter(++ph->meal_counter, &ph->meal_counter, &ph->ph_mutex);
		ft_meal_counter(&ph->data->general_meal_counter, &ph->data->mutex);
	}
	usleep(ph->data->t_eating * 1000);
	pthread_mutex_unlock(&ph->r_fork);
	pthread_mutex_unlock(ph->l_fork);
	ft_sleep_think(ph);
}
