/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:37:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 14:13:07 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_valid_input(t_data *data)
{
	if (data->ph_nb <= 0 || data->ph_nb > 200)
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

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_is_digit(av[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_data_init(char **av, t_data *data)
{
	data->ph_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eating = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->meal = -1;
	data->general_meal_counter = 0;
	data->dead_flag = 0;
	if (av[5])
		data->meal = ft_atoi(av[5]);
	data->t_think = 0;
	if (data->t_eating >= data->t_sleep)
		data->t_think = data->t_eating - data->t_sleep + 1;
	pthread_mutex_init(&data->mutex, NULL);
	return (0);
}

void	ft_init_philo(t_ph *ph, t_data *data, char **av)
{
	int				i;
	struct timeval	time;

	i = 0;
	while (i < data->ph_nb)
	{
		ph[i].id = i + 1;
		ph[i].data = data;
		ph[i].meal_flag = 0;
		if (av[5])
			ph[i].meal_flag = 1;
		ph[i].meal_counter = 0;
		gettimeofday(&time, NULL);
		ph[i].last_meal = time;
		pthread_mutex_init(&ph[i].r_fork, NULL);
		pthread_mutex_init(&ph[i].ph_mutex, NULL);
		if (i)
			ph[i].l_fork = &ph[i - 1].r_fork;
		i++;
	}
	ph[0].l_fork = &ph[data->ph_nb - 1].r_fork;
}
