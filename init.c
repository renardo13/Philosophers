/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:37:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/26 15:59:49 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_negative(t_data *data)
{
	if (data->ph_nb < 0 || data->ph_nb > 200)
		return (-1);
	if (data->t_die < 60 || data->t_die > INT_MAX)
		return (-1);
	if (data->t_eating < 60 || data->t_eating > INT_MAX)
		return (-1);
	if (data->t_sleep < 60 || data->t_sleep > INT_MAX)
		return (-1);
	return (0);
}

int	ft_check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (ft_is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_data_init(char **av, t_data *data)
{
	if (!ft_check_digit(av))
		return (ft_error(1, data));
	data->ph_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eating = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->t_eat = -1;
	if (av[5])
		data->t_eat = ft_atoi(av[5]);
	data->t_think = 0;
	if (data->t_eating >= data->t_sleep)
		data->t_think = data->t_eating - data->t_sleep + 1;
	if (ft_check_negative(data) == -1)
		return (ft_error(1, data));
	pthread_mutex_init(&data->mutex, NULL);
	return (0);
}

void	ft_init_philo(t_ph *ph, t_data *data, char **av)
{
	int	i;

	data->general_meal_counter = 0;
	data->all_ready = 0;
	data->dead_flag = 0;
	gettimeofday(&data->start_time, NULL);
	i = 0;
	while (i < data->ph_nb)
	{
		ph[i].id = i + 1;
		ph[i].data = data;
		ph[i].meal_flag = 0;
		if (av[5])
			ph[i].meal_flag = 1;
		ph[i].meal_counter = 0;
		ph[i].last_meal = data->start_time;
		pthread_mutex_init(&ph[i].r_fork, NULL);
		pthread_mutex_init(&ph[i].ph_mutex, NULL);
		if (i)
			ph[i].l_fork = &ph[i - 1].r_fork;
		i++;
	}
	ph[0].l_fork = &ph[data->ph_nb - 1].r_fork;
}
