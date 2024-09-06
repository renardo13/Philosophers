/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:37:08 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:32:11 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_valid_input(t_data *data)
{
	if (data->ph_nb <= 0 || data->ph_nb > 200)
		return (-1);
	if (data->t_die > INT_MAX)
		return (-1);
	if (data->t_eating > INT_MAX)
		return (-1);
	if (data->t_sleep > INT_MAX)
		return (-1);
	if (data->meal > INT_MAX)
		return (-1);
	return (0);
}

void	ft_sem_init(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print_sem");
	sem_unlink("/meal_sem");
	sem_unlink("/dead_flag");
	sem_unlink("/nb_meal");
	data->forks = sem_open("/forks", O_CREAT, 0660, data->ph_nb);
	if (data->forks == SEM_FAILED)
		return ;
	data->print_sem = sem_open("/print_sem", O_CREAT, 0660, 1);
	if (data->print_sem == SEM_FAILED)
		return ;
	data->meal_sem = sem_open("/meal_sem", O_CREAT, 0660, 1);
	if (data->meal_sem == SEM_FAILED)
		return ;
	data->dead_flag = sem_open("/dead_flag", O_CREAT, 0660, 0);
	if (data->dead_flag == SEM_FAILED)
		return ;
	data->nb_meal = sem_open("/nb_meal", O_CREAT, 0660, 0);
	if (data->nb_meal == SEM_FAILED)
		return ;
}

void	ft_destroy(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_sem);
	sem_close(data->meal_sem);
	sem_close(data->dead_flag);
	sem_close(data->nb_meal);
	sem_unlink("/forks");
	sem_unlink("/print_sem");
	sem_unlink("/meal_sem");
	sem_unlink("/dead_flag");
	sem_unlink("/nb_meal");
	free(data->ph);
}

int	ft_data_init(char **av, t_data *data)
{
	data->ph_nb = ft_atol(av[1]);
	data->t_die = ft_atol(av[2]);
	data->t_eating = ft_atol(av[3]);
	data->t_sleep = ft_atol(av[4]);
	data->meal = -1;
	if (av[5])
		data->meal = ft_atol(av[5]);
	return (0);
}

void	ft_init_philo(t_ph *ph, t_data *data, char **av)
{
	int	i;

	i = 0;
	while (i < data->ph_nb)
	{
		ph[i].t_die = data->t_die;
		ph[i].data = data;
		ph[i].id = i + 1;
		ph[i].meal_flag = 0;
		if (av[5])
			ph[i].meal_flag = 1;
		i++;
	}
}
