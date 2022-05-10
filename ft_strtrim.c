/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:48:07 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/07 14:03:23 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check(char const s1, char const *set)
{
	size_t	x;
	int		a;

	x = 0;
	a = 0;
	while (set[x])
	{
		if (s1 == set[x])
		{
			a++;
			x = 0;
			break ;
		}
		x++;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s1_cpy;
	size_t		i;
	size_t		z;

	i = 0;
	z = 0;
	if (!s1 || !set)
		return (NULL);
	s1_cpy = malloc(ft_strlen(s1) + 1);
	if (!s1_cpy)
		return (NULL);
	while (s1[i])
	{
		if (check(s1[i], set) == 0)
		{
			s1_cpy[z] = s1[i];
			z++;
		}
		i++;
	}
	s1_cpy[++z] = 0;
	return (s1_cpy);
}
