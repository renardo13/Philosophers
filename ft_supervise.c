/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:33 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:01 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_supervise(t_ph *ph, int ph_nb)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < ph_nb)
		{
			if (ft_gettime_from(ft_last_meal_getter(&ph[i].last_meal,
						&ph->data->mutex)) == ft_getter(&ph[i].data->t_die,
					&ph->data->mutex))
			{
				if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
				{
					if (ft_getter(&ph->data->general_meal_counter,
							&ph->data->mutex) == ft_getter(&ph[i].meal_counter,
							&ph->ph_mutex) * ph_nb)
						return ;
				}
				ft_print_die(ph);
				return ;
			}
		}
	}
}
