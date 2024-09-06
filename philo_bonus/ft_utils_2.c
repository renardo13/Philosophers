/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:24:00 by melmarti          #+#    #+#             */
/*   Updated: 2024/09/05 16:24:26 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *str, char *s)
{
	int	i;

	i = 0;
	while (str[i] && s[i] && str[i] == s[i])
		i++;
	return (str[i] - s[i]);
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
