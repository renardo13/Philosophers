/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:15:54 by melmarti          #+#    #+#             */
/*   Updated: 2024/08/26 15:56:48 by melmarti         ###   ########.fr       */
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

int ft_is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
