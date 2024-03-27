/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:37:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:52:37 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_negative(t_data *data)
{
	if (data->ph_nb < 0)
		return (-1);
	if (data->t_die < 60)
		return (-1);
	if (data->t_eating < 60)
		return (-1);
	if (data->t_sleep < 60)
		return (-1);
	if (data->t_eat <= 0)
		return (-1);
	return (0);
}

int	ft_strcmp(char *str, char *s)
{
	int	i;

	i = 0;
	while (str[i] && s[i] && str[i] == s[i])
		i++;
	return (str[i] - s[i]);
}

int	ft_data_init(char **av, t_data *data)
{
	if (ft_atoi(av[1]) > 200)
		return (ft_error(1));
	data->ph_nb = ft_atoi(av[1]);
	if (ft_strcmp(ft_itoa(ft_atoi(av[2])), av[2]))
		return (ft_error(1));
	data->t_die = ft_atoi(av[2]);
	if (ft_strcmp(ft_itoa(ft_atoi(av[3])), av[3]))
		return (ft_error(1));
	data->t_eating = ft_atoi(av[3]);
	if (ft_strcmp(ft_itoa(ft_atoi(av[4])), av[4]))
		return (ft_error(1));
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		if (ft_strcmp(ft_itoa(ft_atoi(av[5])), av[5]))
			return (ft_error(1));
		data->t_eat = ft_atoi(av[5]);
	}
	data->t_think = 0;
	if (data->t_eating >= data->t_sleep)
		data->t_think = data->t_eating - data->t_sleep + 1;
	pthread_mutex_init(&data->mutex, NULL);
	if (ft_check_negative(data) == -1)
		return (ft_error(1));
	return (0);
}

void	ft_init_philo(t_ph *ph, t_data *data, char **av)
{
	int	i;
	int	ph_nb;

	ph_nb = data->ph_nb;
	data->general_meal_counter = 0;
	data->all_ready = 0;
	data->dead_flag = 0;
	gettimeofday(&data->start_time, NULL);
	i = 0;
	while (i < data->ph_nb)
	{
		ph[i].id = i + 1;
		ph[i].data = data;
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
