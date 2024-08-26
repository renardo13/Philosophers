/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:16 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/26 14:48:30 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int code, t_data *data)
{
	if (code == 1)
		write(2, "Parsing error\n", 15);
	else if (code == 2)
		write(2, "malloc error\n", 14);
	else if (code == 3)
		write(2, "Error while creating thread\n", 29);
	if (data && data->ph)
		free(data->ph);
	return (-1);
}
