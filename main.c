/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:02:55 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:54:36 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// threads have common memmory
// pthread_join to block thread execution until another has finished

#include "philo.h"

void	ft_philo_solo(t_ph *ph)
{
	ft_take_right_fork(ph);
	usleep(ph->data->t_die * 1000);
	pthread_mutex_unlock(&ph->r_fork);
	if (ph->meal_flag)
		ft_print_die(ph);
}

void	*ft_routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	while (!ft_getter(&ph->data->all_ready, &ph->data->mutex))
		;
	ft_last_meal_setter(&ph->data->start_time, &ph->last_meal,
		&ph->data->mutex);
	if (ph->id % 2 == 0)
		usleep(2000);
	if (ft_getter(&ph->data->ph_nb, &ph->data->mutex) == 1)
		return (ft_philo_solo(ph), NULL);
	while (!ft_getter(&ph->data->dead_flag, &ph->data->mutex))
	{
		if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
		{
			if (ft_getter(&ph->meal_counter,
					&ph->ph_mutex) == ft_getter(&ph->data->t_eat,
					&ph->ph_mutex))
				break ;
		}
		ft_eat(ph);
	}
	return (NULL);
}

void	ft_philo(t_ph *ph)
{
	int	i;

	i = 0;
	while (i < ph->data->ph_nb)
	{
		if (pthread_create(&ph[i].ph_thread_id, NULL, &ft_routine, &ph[i]) != 0)
		{
			ft_error(3);
			return ;
		}
		i++;
	}
	gettimeofday(&ph->data->start_time, NULL);
	ft_setter(1, &ph->data->all_ready, &ph->data->mutex);
	ft_supervise(ph, ft_getter(&ph->data->ph_nb, &ph->data->mutex));
	i = 0;
	while (i < ph->data->ph_nb)
	{
		pthread_join(ph[i].ph_thread_id, NULL);
		i++;
	}
	if (ft_getter(&ph->meal_flag, &ph->ph_mutex))
		ft_enough_meal(ph);
}

int	main(int ac, char **av)
{
	t_ph	*ph;
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		ph = malloc(sizeof(t_ph) * (atoi(av[1])));
		if (!ph)
			return (ft_error(2));
		if (ft_data_init(av, &data) == -1)
			return (-1);
		ft_init_philo(ph, &data, av);
		ft_philo(ph);
		ft_kill_phil(&data, ph);
	}
	else
		ft_error(1);
	return (0);
}
