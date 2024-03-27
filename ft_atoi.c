/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:48:01 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/27 16:41:08 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_putnbr(char *s, int n, int counter)
{
	long int	nb;
	int			i;

	i = 0;
	nb = n;
	s[counter] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
		i = 1;
	}
	while (counter-- > i)
	{
		s[counter] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}

static int	ft_count_nb(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	size_t	counter;
	char	*s;

	counter = ft_count_nb(n);
	s = malloc(sizeof(char) * counter + 1);
	if (!s)
		return (NULL);
	return (ft_putnbr(s, n, counter));
}

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + (s[i] - 48);
		i++;
	}
	return (nbr * sign);
}
