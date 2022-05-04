/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:13:05 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/04 11:20:38 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_sign(const char *str, size_t n)
{
	int	count;

	count = 0;
	while (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			count++;
		n++;
	}
	if ((count % 2) == 0)
		return (1);
	return (-1);
}

static	int	find_start(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

static	int	find_nbr(const char *str, size_t n)
{
	while (str[n] == '-' || str[n] == '+')
		n++;
	return (n);
}

int	ft_atoi(const char *str)
{
	int		x;
	int		nbr;
	long	result;

	nbr = 0;
	result = 0;
	x = find_nbr(str, find_start(str));
	while (('0' <= str[x]) && (str[x] <= '9'))
	{
		nbr = (int) str[x] - '0';
		result = (result * 10) + nbr;
		x++;
	}
	return (check_sign(str, find_start(str)) * result);
}
