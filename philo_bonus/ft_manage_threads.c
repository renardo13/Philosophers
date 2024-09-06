/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:22:54 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:33:34 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_manage_threads(t_ph *ph, t_data *data)
{
	int	i;
	int	exit;

	i = 0;
	gettimeofday(&data->start_time, NULL);
	while (i < data->ph_nb)
	{
		ph[i].pid = fork();
		if (ph[i].pid == 0)
			ft_routine(&ph[i]);
		i++;
	}
	waitpid(-1, &exit, 0);
	while (i--)
		kill(ph[i].pid, SIGKILL);
	if (exit == 256)
		printf(ORANGE_FLUO "Everyone have finished their meal 🍽️\n" RESET);
	ft_destroy(data);
}
