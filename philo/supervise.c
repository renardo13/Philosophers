/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:33 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 13:16:16 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_supervise(t_ph *ph, int ph_nb)
{
	int	i;

	while (!ft_enough_meal(ph))
	{
		i = -1;
		while (++i < ph_nb)
		{
			if (ft_gettime_from(ft_last_meal_getter(&ph[i].last_meal,
						&ph->data->mutex)) == ft_getter(&ph[i].data->t_die,
					&ph->data->mutex))
			{
				ft_setter(1, &ph->data->dead_flag, &ph->data->mutex);
				pthread_mutex_lock(&ph->data->mutex);
				printf(RED "%ld %d died 💀\n" RESET,
					ft_gettime_from(ph->data->start_time), ph->id);
				pthread_mutex_unlock(&ph->data->mutex);
				return ;
			}
		}
	}
}
