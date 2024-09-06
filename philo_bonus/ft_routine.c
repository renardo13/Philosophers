/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:24:14 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/06 12:33:24 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine(t_ph *ph)
{
	ph->last_meal = ph->data->start_time;
	if (ph->id % 2 == 0)
		usleep(1500);
	if (pthread_create(&ph->supervizor, NULL, &ft_supervise, ph) != 0)
	{
		ft_error(3);
		return ;
	}
	if (ph->data->ph_nb == 1)
		return (ft_philo_solo(ph));
	while (!ft_check_death(ph))
	{
		if (ft_check_meal(ph))
		{
			pthread_join(ph->supervizor, NULL);
			ft_destroy(ph->data);
			exit(1);
		}
		ft_eat(ph);
	}
	pthread_join(ph->supervizor, NULL);
	ft_destroy(ph->data);
	exit(10);
}
