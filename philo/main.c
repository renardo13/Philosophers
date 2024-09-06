/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:02:55 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/28 14:14:38 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_ph	*ph;
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_digit(av) == -1)
			return (ft_error(1));
		ft_data_init(av, &data);
		if (ft_valid_input(&data) == -1)
			return (-1);
		ph = malloc(sizeof(t_ph) * (ft_atoi(av[1])));
		if (!ph)
			return (ft_error(2));
		data.ph = ph;
		ft_init_philo(ph, &data, av);
		ft_manage_threads(ph, &data);
		ft_kill_phil(&data, ph);
	}
	else
		ft_error(1);
	return (0);
}
