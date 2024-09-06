/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:32:00 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 14:02:06 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	ft_last_meal_setter(&ph->data->start_time, &ph->last_meal,
		&ph->data->mutex);
	if (ph->id % 2 == 0)
		usleep(20);
	while (!ft_getter(&ph->data->dead_flag, &ph->data->mutex)
		&& ph->data->ph_nb > 1)
	{
		if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
		{
			if (ft_getter(&ph->meal_counter,
					&ph->ph_mutex) == ft_getter(&ph->data->meal, &ph->ph_mutex))
				break ;
		}
		ft_eat(ph);
	}
	return (NULL);
}

void	ft_manage_threads(t_ph *ph, t_data *data)
{
	int	i;

	i = 0;
	gettimeofday(&data->start_time, NULL);
	while (i < ph->data->ph_nb)
	{
		if (pthread_create(&ph[i].ph_thread_id, NULL, &ft_routine,
				&ph[i]))
		{
			ft_error(3);
			return ;
		}
		i++;
	}
	if (data->ph_nb > 1)
		ft_supervise(ph, ft_getter(&data->ph_nb, &data->mutex));
	else
		ft_philo_solo(ph);
	i = -1;
	while (++i < ph->data->ph_nb)
		pthread_join(ph[i].ph_thread_id, NULL);
}
