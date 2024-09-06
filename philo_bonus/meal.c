/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:03 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:19:35 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_think(t_ph *ph)
{
	ft_write_status(ph, "SLEEP");
	ft_usleep(ph->data->t_sleep, ph);
	ft_write_status(ph, "THINK");
	ft_usleep(2, ph);
	if (ph->data->ph_nb % 2 != 0)
		ft_usleep(100, ph);
}

void	ft_take_forks(t_ph *ph)
{
	sem_wait(ph->data->forks);
	ft_write_status(ph, "FORK");
	sem_wait(ph->data->forks);
	ft_write_status(ph, "FORK");
}

void	ft_eat(t_ph *ph)
{
	struct timeval	new_last_meal;

	ft_take_forks(ph);
	ft_write_status(ph, "EAT");
	gettimeofday(&new_last_meal, NULL);
	sem_wait(ph->data->meal_sem);
	ph->last_meal = new_last_meal;
	sem_post(ph->data->meal_sem);
	ft_usleep(ph->data->t_eating, ph);
	if (ft_check_meal(ph))
		return ;
	sem_post(ph->data->nb_meal);
	sem_post(ph->data->forks);
	sem_post(ph->data->forks);
	ft_sleep_think(ph);
}
