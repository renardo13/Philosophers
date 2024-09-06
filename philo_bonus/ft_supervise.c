/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:33 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:35:12 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_ph *ph)
{
	if (ph->data->dead_flag->__align)
		return (1);
	return (0);
}

int	ft_check_meal(t_ph *ph)
{
	if (ph->meal_flag)
	{
		if (ph->data->nb_meal->__align >= ph->data->ph_nb * ph->data->meal)
			return (1);
	}
	return (0);
}

void	*ft_supervise(void *arg)
{
	t_ph	*ph;
	long	ms;

	ph = (t_ph *)arg;
	while (1)
	{
		sem_wait(ph->data->meal_sem);
		ms = ft_gettime_from(ph->last_meal);
		sem_post(ph->data->meal_sem);
		if (ms >= ph->t_die)
		{
			if (!ft_check_death(ph))
			{
				sem_post(ph->data->dead_flag);
				sem_wait(ph->data->print_sem);
				if (!ft_check_meal(ph))
					printf(RED "%ld %d died 💀\n",
						ft_gettime_from(ph->data->start_time), ph->id);
			}
			return (NULL);
		}
	}
	return (NULL);
}
