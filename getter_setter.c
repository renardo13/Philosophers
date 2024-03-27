/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:42 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 13:31:42 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_meal_counter(long *flag, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*flag += 1;
	pthread_mutex_unlock(mutex);
}

void	ft_last_meal_setter(struct timeval *val, struct timeval *last_meal,
		pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*last_meal = *val;
	pthread_mutex_unlock(mutex);
}

void	ft_setter(long val, long *flag, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*flag = val;
	pthread_mutex_unlock(mutex);
}

struct timeval	ft_last_meal_getter(struct timeval *last_meal,
		pthread_mutex_t *mutex)
{
	struct timeval	time;

	pthread_mutex_lock(mutex);
	time = *last_meal;
	pthread_mutex_unlock(mutex);
	return (time);
}

long	ft_getter(long *val, pthread_mutex_t *mutex)
{
	long	value;

	pthread_mutex_lock(mutex);
	value = *val;
	pthread_mutex_unlock(mutex);
	return (value);
}
