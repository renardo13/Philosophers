/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:49:00 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 14:16:08 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime_from(struct timeval start)
{
	struct timeval	now;
	long			time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) - (start.tv_sec * 1000);
	time += (now.tv_usec / 1000) - (start.tv_usec / 1000);
	return (time);
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
		if (ft_getter(&ph->data->dead_flag, &ph->data->mutex))
			return ;
		t_curr = ft_gettime_from(start);
		usleep(time / 10);
	}
}
